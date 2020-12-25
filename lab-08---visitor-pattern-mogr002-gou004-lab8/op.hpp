#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <string>

using namespace std;

class Op : public Base {
    public:
        Op(double value) : Base() {
		num = value;
		string_num = to_string(num); //convert double to string value
	 }
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return string_num; }
	Base* get_left() {return nullptr;}
	Base* get_right() {return nullptr;}
	virtual Iterator* create_iterator() {
		return new NullIterator(this);
	}
	void accept(CountVisitor* visitor) {visitor->visit_op();}

    private:
	double num;
	string string_num;
};

#endif //__OP_HPP__
