#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
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
    private:
	double num;
	string string_num;
};

#endif //__OP_HPP__
