#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include<stdlib.h>

using namespace std;

class Rand : public Base {
	public:
		Rand(): Base(){
			num = rand() % 100;
			string_num = to_string(num);
		}
		virtual double evaluate(){ return num; }
		virtual string stringify() {return string_num;}
	private:
		double num;
		string string_num; 

};

#endif





