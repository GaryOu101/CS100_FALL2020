#ifndef __NTENOPMOCK_HPP__
#define __NTENOPMOCK_HPP__

using namespace std;

#include "../base.hpp"

class NTenOpMock : public Base {
    public:
        NTenOpMock() {};

        virtual double evaluate() { return -10.5; }
        virtual string stringify() { return "-10.5"; }
};

#endif
