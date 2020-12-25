#include "gtest/gtest.h"
#include "factory.hpp"


TEST(Test, Add) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "+" ; test_val[3] = "3";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("5.000000 + 3.000000", resultS);
	EXPECT_EQ(8, resultE);
}
/*
TEST(Test, Add1) {
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "-5"; test_val[2] = "+" ; test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        string resultS = test->stringify();
        double resultE = test->evaluate();
        EXPECT_EQ("-5.000000 + 3.000000", resultS);
        EXPECT_EQ(-2, resultE);
}
*/
TEST(Test, Div) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "15"; test_val[2] = "/"; test_val[3] = "3";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("15.000000 / 3.000000", resultS);
	EXPECT_EQ(5, resultE);
}
/*
TEST(Test, Div1) {
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "-15"; test_val[2] = "/"; test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        string resultS = test->stringify();
        double resultE = test->evaluate();
        EXPECT_EQ("-15.000000 / 3.000000", resultS);
        EXPECT_EQ(-5, resultE);
}
*/
TEST(Test, Mult) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "*"; test_val[3] = "3";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("5.000000 * 3.000000", resultS);
	EXPECT_EQ(15, resultE);
}
/*
TEST(Test, Mult1) {
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "-5"; test_val[2] = "*"; test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        string resultS = test->stringify();
        double resultE = test->evaluate();
        EXPECT_EQ("-5.000000 * 3.000000", resultS);
        EXPECT_EQ(-15, resultE);
}
*/
TEST(Test, Pow) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "**"; test_val[3] = "2";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("5.000000 ** 2.000000", resultS);
	EXPECT_EQ(25, resultE);
}

TEST(Test, Pow1) {
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "**"; test_val[3] = "0";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        string resultS = test->stringify();
        double resultE = test->evaluate();
        EXPECT_EQ("5.000000 ** 0.000000", resultS);
        EXPECT_EQ(1, resultE);
}

TEST(Test, Sub) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "-"; test_val[3] = "3";
	Factory* f = new Factory();
	Base* test = f->parse(test_val, 4);
	string resultS = test->stringify();
	double resultE = test->evaluate();
	EXPECT_EQ("5.000000 - 3.000000", resultS);
	EXPECT_EQ(2, resultE);
}
/*
TEST(Test, Sub1) {
        char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "-5"; test_val[2] = "-"; test_val[3] = "3";
        Factory* f = new Factory();
        Base* test = f->parse(test_val, 4);
        string resultS = test->stringify();
        double resultE = test->evaluate();
        EXPECT_EQ("-5.000000 - 3.000000", resultS);
        EXPECT_EQ(-8, resultE);
}
*/
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

