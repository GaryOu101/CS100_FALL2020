#include "gtest/gtest.h"

#include "iterator_test.hpp"

TEST(IteratorTest, SubBinaryTest){
    Base* num1 = new Op(3);
        Base* num2 = new Op(1);
        Sub* temp = new Sub(num1, num2);
        Base* num3 = new Op(4);
        Base* dummy = new Add(temp, num3);

    Iterator* it = dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();
       it->first();
    while(!it->is_done()) {
            it->current()->accept(visit);
               it->next();
        }

        EXPECT_EQ(visit->op_count(), 1);
        EXPECT_EQ(visit->sub_count(), 1);
        EXPECT_EQ(visit->add_count(), 0);
}
TEST(IteratorTest, PowBinaryTest) {
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);
    Pow* temp = new Pow(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first(); //initialize iterator
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->pow_count(), 1);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(Test, Test4) {
	Op* op3 = new Op(3);
	Op* opN5 = new Op(-5);
	Op* op11 = new Op(11);
	Op* op0 = new Op(0);
	
	Op* op5 = new Op(5);
	Op* op2 = new Op(2);
	Op* op1 = new Op(1);
	Op* op121 = new Op(121);

	Sub* sub1 = new Sub(op1, op2);
	Div* div1 = new Div(op121, op11);

	Add* add1 = new Add(op3, opN5);
	Mult* mult1 = new Mult(op11, op0);

	Sub* first = new Sub(sub1, div1);
	Pow* second = new Pow(add1, mult1);

	Sub* dummy = new Sub(first, second);
	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	test2->first();
	while (test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}
	EXPECT_EQ(test1->add_count(), 1);
	EXPECT_EQ(test1->sub_count(), 2);
	EXPECT_EQ(test1->mult_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
	EXPECT_EQ(test1->pow_count(), 1);
	EXPECT_EQ(test1->op_count(), 8);
}

TEST (Test, Test5) {
	Op* op125 = new Op(125);
        Op* op525 = new Op(525);
        Op* op2302 = new Op(2302);
        Op* op5971 = new Op(5971);
	
	Sub* first = new Sub(op125, op525);
	Div* second = new Div (first, op2302);
	Add* dummy = new Add(second, op5971);
	
	CountVisitor *test1 = new CountVisitor();
	PreorderIterator *test2 = new PreorderIterator(dummy);
	test2->first();
	
	while(test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}

	EXPECT_EQ(test1->sub_count(), 1);
	EXPECT_EQ(test1->div_count(), 1);
}

TEST(Test, Test6) {
	Op* op102464 = new Op(102464);
	Op* op89797 = new Op(89797);
	Op* opN132 = new Op(-132);
	Op* op987565 = new Op(987565);
	
	Op* op465 = new Op(465);
	Op* op2997 = new Op(2997);
	Op* opN98745 = new Op(-98745);
	Op* opN652318 = new Op(-652318);

	Mult* mult1 = new Mult(op102464, op89797);
	Div* div1 = new Div(mult1, opN132);

	Add* add1 = new Add(op987565, div1);
	Div* div2 = new Div(add1, op2997);

	Sub* first = new Sub(div2, opN98745);
	Pow* second = new Pow(mult1, first);

	Sub* dummy = new Sub(first, second);
	CountVisitor* test1 = new CountVisitor();
	PreorderIterator* test2 = new PreorderIterator(dummy);
	test2->first();
	while (test2->is_done() == false) {
		test2->current()->accept(test1);
		test2->next();
	}
	EXPECT_EQ(test1->add_count(), 2);
	EXPECT_EQ(test1->sub_count(), 2);
	EXPECT_EQ(test1->mult_count(), 3);
	EXPECT_EQ(test1->div_count(), 4);
	EXPECT_EQ(test1->pow_count(), 1);
	EXPECT_EQ(test1->op_count(), 14);
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
