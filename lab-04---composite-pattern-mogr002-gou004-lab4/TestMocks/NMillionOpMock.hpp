#ifndef __NMILLIONOPMOCK_HPP__
#define __NMILLIONOPMOCK_HPP__

using namespace std;

#include "../base.hpp"

class NMillionOpMock : public Base {
    public:
	NMillionOpMock() {};

	virtual double evaluate() { return -1000000.0; }
	virtual string stringify() { return "-1000000.0"; } 
};

#endif
