#ifndef __CONTAINER_TEST_HPP__
#define __CONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "VectorContainer.hpp"
#include "ListContainer.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"


TEST(VectorContainerTest, addElement){
        Op* five = new Op(5);
        VectorContainer* test = new VectorContainer();
        test->add_element(five);
        EXPECT_EQ(test->at(0)->evaluate(), 5);
}

TEST(VectorContainerTest, Swap){
	Op* three = new Op(3);
	Op* four = new Op(4);
	VectorContainer* test = new VectorContainer();
	test->add_element(three);
	test->add_element(four);
	test->swap(0,1);
	EXPECT_EQ(test->at(0)->evaluate(),4);
	EXPECT_EQ(test->at(1)->evaluate(),3);
}

TEST(VectorContainerTest, print){
	Op* three = new Op(3);
        Op* four = new Op(4);
	Add* plus = new Add(three, four);
        VectorContainer* test = new VectorContainer();
	test->add_element(plus);
	string s = "3 + 4";
	cout << s << endl;
	test->print();

}

TEST(VectorContainerTest, size){
	Op* three = new Op(3);
        Op* four = new Op(4);
	VectorContainer* test = new VectorContainer();
	test->add_element(three);
	test->add_element(four);
	EXPECT_EQ(test->size(), 2);
}

TEST(VectorContainerTest, at){
	Op* three = new Op(3);
        Op* four = new Op(4);
        VectorContainer* test = new VectorContainer();
        test->add_element(three);
        test->add_element(four);
	EXPECT_EQ(test->at(1)->evaluate(), 4);
}


//==================================================================
TEST(ListContainerTest, addElement){
        Op* five = new Op(5);
        ListContainer* test = new ListContainer();
        test->add_element(five);
        EXPECT_EQ(test->at(0)->evaluate(), 5);
}

TEST(ListContainerTest, Swap){
        Op* three = new Op(3);
        Op* four = new Op(4);
        ListContainer* test = new ListContainer();
        test->add_element(three);
        test->add_element(four);
        test->swap(0,1);
        EXPECT_EQ(test->at(0)->evaluate(),4);
        EXPECT_EQ(test->at(1)->evaluate(),3);
}

TEST(ListContainerTest, print){
        Op* three = new Op(3);
        Op* four = new Op(4);
        Add* plus = new Add(three, four);
        ListContainer* test = new ListContainer();
        test->add_element(plus);
        string s = "3 + 4";
        cout << s << endl;
        test->print();

}

TEST(ListContainerTest, size){
        Op* three = new Op(3);
        Op* four = new Op(4);
        ListContainer* test = new ListContainer();
        test->add_element(three);
        test->add_element(four);
        EXPECT_EQ(test->size(), 2);
}

TEST(ListContainerTest, at){
        Op* three = new Op(3);
        Op* four = new Op(4);
        ListContainer* test = new ListContainer();
        test->add_element(three);
        test->add_element(four);
        EXPECT_EQ(test->at(1)->evaluate(), 4);
}






#endif
