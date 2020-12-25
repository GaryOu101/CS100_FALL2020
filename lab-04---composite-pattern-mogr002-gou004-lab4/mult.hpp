#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"

using namespace std;

class Mult: public Base {
	public:
		Mult(Base* leftOp, Base* rightOp):Base(){
			leftNum = leftOp -> evaluate();
			rightNum = rightOp -> evaluate();
			leftStr = leftOp -> stringify();
			rightStr = rightOp -> stringify();
		}
		virtual double evaluate(){
			return (leftNum * rightNum);
		}
		virtual string stringify(){
			return (leftStr + " * " + rightStr);
		}
	private:
		string leftStr;
		string rightStr;
		double leftNum;
		double rightNum;
};
#endif

