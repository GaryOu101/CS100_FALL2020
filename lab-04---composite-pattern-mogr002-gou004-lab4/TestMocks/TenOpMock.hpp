#ifndef __TENOPMOCK_HPP__
#define __TENOPMOCK_HPP__

using namespace std;

#include "../base.hpp"

class TenOpMock : public Base {
    public:
        TenOpMock() {};

        virtual double evaluate() { return 10.5; }
        virtual string stringify() { return "10.5"; }
};

#endif
