#ifndef __ONEOPMOCK_HPP__
#define __ONEOPMOCK_HPP__

using namespace std;

#include "../base.hpp"

class OneOpMock : public Base {
    public:
        OneOpMock() {};

        virtual double evaluate() { return 1.0; }
        virtual string stringify() { return "1.0"; }
};

#endif
