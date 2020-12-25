#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"





TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero){
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringZero){
        Op* test = new Op(0);
        EXPECT_EQ(test->stringify(), "0.000000");
}
TEST(OpTest, OpEvaluateNegNum){
        Op* test = new Op(-9);
        EXPECT_EQ(test->evaluate(), -9);
}

TEST(OpTest, OpStringNegNum){
        Op* test = new Op(-9);
        EXPECT_EQ(test->stringify(), "-9.000000");
}

TEST(OpTest, OpEvaluateRationalNum){
	Op* test = new Op(-5.5);
	EXPECT_EQ(test->evaluate(), -5.500000);
}

TEST(OpTest, OpStringRationalNum){
	Op* test = new Op(-5.5);
	EXPECT_EQ(test->stringify(), "-5.500000");
}



TEST(RandTest, RandEvaluateNum){
	Rand* test = new Rand();
	EXPECT_LT(test->evaluate(), 100);
}

TEST (RandTest, RandStringNum){          
	Rand* test = new Rand(); 
	EXPECT_LT(stoi(test->stringify()), 100); 
}


TEST(MultTest, MultEvalauate){
	Op* left = new Op(5);
	Op* right = new Op(7);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 35.000000);
}

TEST(MultTest, MultEvaluateNN){
	Op* left = new Op(-5);
	Op* right = new Op(-7);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 35.000000);
}

TEST(MultTest, MultEvaluateNP){
	Op* left = new Op(-5);
	Op* right = new Op(7);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), -35.00000);
}

TEST(MultTest, MultEvaluateZ){
	Op* left = new Op(0);
	Op* right = new Op(5);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultString){
	Op* left = new Op(5);
	Op* right = new Op(6);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "5.000000 * 6.000000");

}

TEST(MultTest, MultString2) {
	Op* left = new Op(0);
	Op* right = new Op(0);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "0.000000 * 0.000000");
}

TEST(MultTest, MultString3) {
	Op* left = new Op(-5);
	Op* right = new Op(-10);
	Mult* test = new Mult(left, right);
	EXPECT_EQ(test->stringify(), "-5.000000 * -10.000000");
}

TEST(DivTest, DivEvaluate){
	Op* left = new Op(10);
	Op* right = new Op(2);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 5.000000);
}

TEST(DivTest, DivEvaluateNN) {
	Op* left = new Op(-15);
	Op* right = new Op(-3);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 5.000000);
}

TEST(DivTest, DivEvaluateNP) {
	Op* left = new Op(-15);
	Op* right = new Op(3);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), -5.000000);
}

TEST(DivTest, DivEvaluateZ) {
	Op* left = new Op(0);
	Op* right = new Op(5);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->evaluate(), 0.000000);
}

TEST(DivTest, DivString){
	Op* left = new Op(35);
	Op* right = new Op(5);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->stringify(), "35.000000 / 5.000000");
} 

TEST(DivTest, DivString2) {
	Op* left = new Op(-10);
	Op* right = new Op(-5);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->stringify(), "-10.000000 / -5.000000");
}

TEST(DivTest, DivString3) {
	Op* left = new Op(5);
	Op* right = new Op(-10);
	Div* test = new Div(left, right);
	EXPECT_EQ(test->stringify(), "5.000000 / -10.000000");
}	

TEST(DivTest, DivFractionEvaluate){
	Op* left = new Op(1);
	Op* right = new Op(2);
	Div* test = new Div(left,right);
	EXPECT_EQ(test->evaluate(), 0.500000);
}
	
TEST(AddTest, AddEvaluatePositive){
	Op* left = new Op(1);
	Op* right = new Op(5);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 6.000000);
}

TEST(AddTest, AddEvaluateNegative) {
	Op* left = new Op(1);
	Op* right = new Op(-5);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), -4.00000);
}

TEST(AddTest, AddEvaluateNN) {
	Op* left = new Op(-5);
	Op* right = new Op(-10);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), -15.000000);
}

TEST(AddTest, AddEvaluateZ) {
	Op* left = new Op(0);
	Op* right = new Op(0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 0.000000);
}

TEST(AddTest, AddEvaluateNP) {
	Op* left = new Op(20);
	Op* right = new Op(-5);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->evaluate(), 15.000000);
}

TEST(AddTest, AddString) {
	Op* left = new Op(5);
	Op* right = new Op(10);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(), "5.000000 + 10.000000");
}

TEST(AddTest, AddString2) {
	Op* left = new Op(-5);
	Op* right = new Op(-10);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(), "-5.000000 + -10.000000");
}

TEST(AddTest, AddString3) {
	Op* left = new Op(0);
	Op* right = new Op(0);
	Add* test = new Add(left, right);
	EXPECT_EQ(test->stringify(), "0.000000 + 0.000000");
}

TEST(SubTest, SubEvaluatePositive){
        Op* left = new Op(5);
        Op* right = new Op(4);
        Sub* test = new Sub(left, right);
        EXPECT_EQ(test->evaluate(), 1.000000);
}

TEST(SubTest, SubEvaluateNegative) {
        Op* left = new Op(-1);
        Op* right = new Op(5);
        Sub* test = new Sub(left, right);
        EXPECT_EQ(test->evaluate(), -6.00000);
}

TEST(SubTest, SubEvaluateNN) {
	Op* left = new Op(-5);
	Op* right = new Op(-11);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), 6.000000);
}

TEST(SubTest, SubEvaluatePN) {
	Op* left = new Op(10);
	Op* right = new Op(-2);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), 12.000000);
}

TEST(SubTest, SubEvaluateZ) {
	Op* left = new Op(0);
	Op* right = new Op(0);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->evaluate(), 0.000000);
}

TEST(SubTest, SubString) {
        Op* left = new Op(15);
        Op* right = new Op(10);
        Sub* test = new Sub(left, right);
        EXPECT_EQ(test->stringify(), "15.000000 - 10.000000");
}

TEST(SubTest, SubString2) {
	Op* left = new Op(-10);
	Op* right = new Op(-7);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->stringify(), "-10.000000 - -7.000000");
}

TEST(SubTest, SubString3) {
	Op* left = new Op(0);
	Op* right = new Op(-4);
	Sub* test = new Sub(left, right);
	EXPECT_EQ(test->stringify(), "0.000000 - -4.000000");
}

TEST(PowTest, PowEvaluate){
        Op* left = new Op(2);
        Op* right = new Op(3);
        Pow* test = new Pow(left, right);
        EXPECT_EQ(test->evaluate(), 8.000000);
}

TEST(PowTest, PowEvaluateNP) {
	Op* left = new Op(-2);
	Op* right = new Op(4);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 16.000000);
}

TEST(PowTest, PowEvaluateZ) {
	Op* left = new Op(5);
	Op* right = new Op(0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->evaluate(), 1.000000);
}

TEST(PowTest, PowString) {
        Op* left = new Op(5);
        Op* right = new Op(10);
        Pow* test = new Pow(left, right);
        EXPECT_EQ(test->stringify(), "5.000000 ** 10.000000");
}

TEST(PowTest, PowString2) {
	Op* left = new Op(-2);
	Op* right = new Op(5);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->stringify(), "-2.000000 ** 5.000000");
}

TEST(PowTest, PowString3) {
	Op* left = new Op(-3);
	Op* right = new Op(-4);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->stringify(), "-3.000000 ** -4.000000");
}

TEST(PowTest, PowString4) {
	Op* left = new Op(3);
	Op* right = new Op(0);
	Pow* test = new Pow(left, right);
	EXPECT_EQ(test->stringify(), "3.000000 ** 0.000000");
}

#endif //__OP_TEST_HPP__
