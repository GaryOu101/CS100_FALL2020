#ifndef __POW_HPP__
#define __POW_HPP__

#include "op.hpp"
#include <math.h>   //pow function

using namespace std;

class Pow : public Base{
	public:
		Pow(Base* leftOp, Base* rightOp):Base(){
			leftNum = leftOp -> evaluate();
			rightNum =  rightOp -> evaluate();
			leftStr = leftOp -> stringify();
			rightStr = rightOp -> stringify();
		}
		double evaluate(){
			return (pow(leftNum, rightNum));
		}
		string stringify(){
			return (leftStr + " ** " + rightStr);
		}
	private:
		double leftNum;
		double rightNum;
		string leftStr;
		string rightStr;
};

#endif	
