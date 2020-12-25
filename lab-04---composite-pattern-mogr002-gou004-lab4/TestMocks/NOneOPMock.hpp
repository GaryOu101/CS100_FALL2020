#ifndef __NONEOPMOCK_HPP__
#define __NONEOPMOCK_HPP__

using namespace std;

#include "../base.hpp"

class NOneOpMock : public Base {
    public:
	NOneOpMock() {};

	virtual double evaluate() { return -1.0; }
	virtual string stringify() { return "-1"; } 
};

#endif
