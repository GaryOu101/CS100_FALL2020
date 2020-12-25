#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "op.hpp"

using namespace std;

class Sub: public Base {
	public:
		Sub(Base* leftOp,Base* rightOp):Base(){
			leftNum = leftOp -> evaluate();
			rightNum = rightOp -> evaluate();
			leftStr = leftOp -> stringify();
			rightStr = rightOp -> stringify();
		}
		double evaluate(){
			return(leftNum - rightNum);
		}
		string stringify(){
			return(leftStr + " - " + rightStr);
		}
	private:
		string leftStr;
		string rightStr;
		double leftNum;
		double rightNum;
};
#endif
