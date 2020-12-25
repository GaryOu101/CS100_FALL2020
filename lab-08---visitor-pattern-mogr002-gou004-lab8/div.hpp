#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include "visitor.hpp"

using namespace std;

class Div: public Base {
	public:
		Div(Base* leftOp, Base* rightOp):Base(){
			this->left_child = leftOp;
			this->right_child = rightOp;
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
		Base* get_left() {return this->left_child;}
		Base* get_right() {return this->right_child;}
		Iterator* create_iterator() {return new BinaryIterator(this);}
		void accept(CountVisitor* visitor) {visitor->visit_div();}

	private:
		string leftStr;
		string rightStr;
		double leftNum;
		double rightNum;
		Base* left_child;
		Base* right_child;
};
#endif
