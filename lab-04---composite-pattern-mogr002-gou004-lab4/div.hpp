#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"

using namespace std;

class Div: public Base {
	public:
		Div(Base* leftOp, Base* rightOp):Base(){
			leftNum = leftOp -> evaluate();
			rightNum = rightOp -> evaluate();
			leftStr = leftOp -> stringify();
			rightStr = rightOp -> stringify();
		}
		virtual double evaluate(){
			return (leftNum / rightNum);
		}
		virtual string stringify(){
			return (leftStr + " / " + rightStr);
		}
	private:
		string leftStr;
		string rightStr;
		double leftNum;
		double rightNum;
};
#endif
