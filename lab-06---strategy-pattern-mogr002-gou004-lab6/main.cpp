#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "VectorContainer.hpp"
#include "ListContainer.hpp"
#include "SelectionSort.hpp"
#include "BubbleSort.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    
    /*
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    */

    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* vector_container = new VectorContainer();
    vector_container->add_element(TreeA);
    vector_container->add_element(TreeB);
    vector_container->add_element(TreeC);

    cout << "Vector Container (unsorted): " << endl;
    vector_container->print(); 
    vector_container->set_sort_function(new SelectionSort());
    vector_container->sort();
    cout << "Calling selection sort..." << endl << endl;
    cout << "Vector Container (sorted): " << endl;
    vector_container->print();   
    cout << endl;

    Op* one = new Op(1);
    Op* five = new Op(5);
    Mult* TreeD = new Mult(one, five);

    Op* eight = new Op(8);
    Op* nine = new Op(9);
    Add* TreeE = new Add(eight, nine);

    ListContainer* list_container = new ListContainer();
    list_container->add_element(TreeA);
    list_container->add_element(TreeD);
    list_container->add_element(TreeE);

    cout << "List Container (unsorted): " << endl;
    list_container->print();
    list_container->set_sort_function(new BubbleSort());
    list_container->sort();
    cout << "Calling bubble sort..." << endl << endl;
    cout << "List Container (sorted): " << endl;
    list_container->print();   

    return 0;
}
