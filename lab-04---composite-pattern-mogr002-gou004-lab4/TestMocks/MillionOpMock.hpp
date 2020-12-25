#ifndef __MILLIONOPMOCK_HPP__
#define __MILLIONOPMOCK_HPP__

using namespace std;

#include "../base.hpp"

class MillionOpMock : public Base {
    public:
        MillionOpMock() {};

        virtual double evaluate() { return 1000000.0; }
        virtual string stringify() { return "1000000.0"; }
};

#endif
