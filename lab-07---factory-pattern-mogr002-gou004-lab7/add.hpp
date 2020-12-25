#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"

using namespace std;

class Add : public Base{
	public:
		Add(Base* leftOp, Base* rightOp) : Base(){
			leftNum = leftOp -> evaluate();
			rightNum = rightOp -> evaluate();
			leftStr = leftOp -> stringify();
			rightStr = rightOp -> stringify();
		}
		double evaluate(){
			return (leftNum + rightNum);
		}
		string stringify(){
			return (leftStr + " + " + rightStr);
		}

	private:
		string leftStr;
		string rightStr;
		double leftNum;
		double rightNum;
};

#endif
