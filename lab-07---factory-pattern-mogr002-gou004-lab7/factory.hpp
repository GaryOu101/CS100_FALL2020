#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include <stack>
#include <queue>

using namespace std;

class base;

class Factory {
	public:
		Factory(){};
		Base* parse(char** input, int length) { //takes in a pointer to an array of chars, length of the array
			queue <char*> q;			//example input: ./calculator 5 + 3 * 6
			stack <char*> s;
			string a;
			for (int i = 1; i < length; ++i){  // loop through all the commands except ./calculator
				a = static_cast<string>(input[i]); //puts the char of arrays into string a 
				if (isdigit(a.at(0))) { //check if digit
					q.push(input[i]);
				} else if (a == "+" || a == "-" || a == "*" || a == "/" || a == "**"){ // check if operator
					while(!s.empty()){	//we store the operand into queue, then pop it back into stack when 2 operators are pushed to stack.
						q.push(s.top()); 
						s.pop();
					}
					s.push(input[i]);
				}
				else{
					cout << "Invalid input" << endl;
					return nullptr;
				}
			}
			while(!s.empty()){
				q.push(s.top());
				s.pop();
			}
			queue<Base*> q2;
			Base* temp1;
			Base* temp2;
			Base* temp3;
			double temp4;
			while (!q.empty()){
				a = static_cast<string>(q.front()); // turn each char into string
				if (a == "+"){			// we determine what type of object(add,sub,mult...) we should create through the char input
					temp2 = q2.front(); //captures operand 1 into temp2
					q2.pop();
					temp3 = q2.front(); //captures operand 2 into temp3
					q2.pop();
					temp1 = new Add(temp2, temp3);
					q2.push(temp1);
					q.pop();             // we determine what type of object(add,sub,mult...) we should create through the char input
				}else if (a ==  "-"){
	
        	        	        temp2 = q2.front(); 
                	      	  	q2.pop();
                       			temp3 = q2.front(); 
                       			q2.pop();
                       			temp1 = new Sub(temp2, temp3);
                        		q2.push(temp1);
                        		q.pop();       
				}else if (a == "*"){
					temp2 = q2.front();
					q2.pop();
					temp3 = q2.front();
					q2.pop();
					temp1 = new Mult(temp2, temp3);
					q2.push(temp1);
					q.pop();
				}else if (a == "/") {
					temp2 = q2.front();
					q2.pop();
					temp3 =  q2.front();
					q2.pop();
					temp1 = new Div(temp2, temp3);
					q2.push(temp1);
					q.pop();
				}else if ( a == "**"){
					temp2 = q2.front();
					q2.pop();
					temp3 = q2.front();
					q2.pop();
					temp1 = new Pow(temp2, temp3);
					q2.push(temp1);
					q.pop();

				}else {
					temp4 = stod(a);     //if digit, create op objects. 
					temp1 = new Op(temp4);
					q.pop();
					q2.push(temp1);
				}	
			
			}
			return q2.front();
		}

};

#endif

		
	












