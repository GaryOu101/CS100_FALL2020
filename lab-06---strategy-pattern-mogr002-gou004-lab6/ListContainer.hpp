#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"
#include <list>

using namespace std;

class ListContainer : public Container {
	private:
		list<Base*> l;
	public:
		ListContainer() : Container() {};
		ListContainer(Sort* function){
			sort_function = function;
		}
		void set_sort_function(Sort* sort_function) {
			this->sort_function = sort_function;
		}
		void add_element(Base* element){
			l.push_back(element);
		}
	
		void print(){
			for (list<Base*>::iterator i = l.begin(); i != l.end(); ++i){
			cout << (*i)->stringify() << endl; //fix maybe
			}
		}
		
		void sort(){
			if(sort_function == nullptr){
				throw string("No sorting algorithm entered");
			}
			else{
				sort_function->sort(this);
			}
		}
		void swap(int num1, int num2) {
			auto temp1 = next(l.begin(), num1);
			auto temp2 = next(l.begin(), num2);
			iter_swap(temp1, temp2);
		}
		Base* at(int i) {
			if(i < 0){
				throw string("Cannot reach a negative index");
			}
			int count = 0;
			for(list<Base*>::iterator it = l.begin(); it != l.end(); it++){
				if(count == i){
					return *it;
				}
				count++;
			}
			throw string("Input is  larger than list size");
		}

		int size(){
			int count = 0;
			for (list<Base*>::iterator it = l.begin(); it != l.end(); it++){
				count++;
			}
			return count;
		}
};

#endif
		

