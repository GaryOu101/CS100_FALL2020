#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"
#include "visitor.hpp"

using namespace std;

class Add : public Base{
	public:
		Add(Base* leftOp, Base* rightOp) : Base(){
			this->left_child = leftOp;
			this->right_child = rightOp;
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
		Base* get_left() {return this->left_child;}
		Base* get_right() {return this->right_child;}
		Iterator* create_iterator() {return new BinaryIterator(this);}
		void accept(CountVisitor* visitor) {visitor->visit_add();}

	private:
		string leftStr;
		string rightStr;
		double leftNum;
		double rightNum;
		Base* left_child;
		Base* right_child;
};

#endif
