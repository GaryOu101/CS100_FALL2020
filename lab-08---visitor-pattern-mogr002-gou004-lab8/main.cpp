#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "visitor.hpp"

int main() {
    Base* num1 = new Op(3);
    Base* num2 = new Op(1);
    Sub* temp = new Sub(num1, num2);
    Base* num3 = new Op(4);
    Base* dummy = new Add(temp, num3);
    Iterator* it = dummy->create_iterator();
    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
    it->current()->accept(visit);
    it->next();
    }
    std::cout << "SubCount: " << visit->sub_count() << std::endl;
    std::cout << "OpCount: " << visit->op_count()  << std::endl;
    std::cout << "AddCount: " << visit->add_count() << std::endl;
    return 0;
}

