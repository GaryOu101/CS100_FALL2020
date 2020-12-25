#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"

#include <iostream>
#include <vector>

using namespace std;

class VectorContainer : public Container {
	private:
		vector <Base*> v;
	public:
		VectorContainer(){
			sort_function = nullptr;
		}
		VectorContainer(Sort* function){
			sort_function = function;
		}
	void set_sort_function(Sort* sort_function) {
		this->sort_function = sort_function;
	}
	void add_element(Base* element) {
		v.push_back(element);
	}

	void print() {
		for(unsigned int i = 0; i < v.size(); i++) {
			cout << v.at(i)->stringify() << endl;
		}
	}

	void sort(){
		if (sort_function == nullptr) {
			throw string ("No sorting function entered");
		}
		else{
			sort_function->sort(this);
		}
	}

        void swap(int num1, int num2){
                Base* temp = v.at(num1);
                v.at(num1) = v.at(num2);
                v.at(num2) = temp;
        }

        Base* at(int i){
                return v.at(i);
        }

        int size(){
                return v.size();
        }
};

#endif



