#ifndef __POW_HPP__
#define __POW_HPP__

#include "op.hpp"
#include "visitor.hpp"
#include <math.h>   //pow function

using namespace std;

class Pow : public Base{
	public:
		Pow(Base* leftOp, Base* rightOp):Base(){
			this->left_child = leftOp;
			this->right_child = rightOp;
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
		Base* get_left() {return this->left_child;}
		Base* get_right() {return this->right_child;}
		Iterator* create_iterator() {return new BinaryIterator(this);}
		void accept(CountVisitor* visitor) {visitor->visit_pow();}

	private:
		double leftNum;
		double rightNum;
		string leftStr;
		string rightStr;
		Base* left_child;
		Base* right_child;
};

#endif	
