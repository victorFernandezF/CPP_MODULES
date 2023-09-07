/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarSerializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:45:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/01 10:39:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cmath>

Base::~Base(){};

int getRandomNumber(){
	int  random;
    srand(time(0));
    random = rand() % 3 + 1;
	return random;
}

// Pointers can be null, Dynamic_cast will return null if fails.
// So no problem, if the cast is success we know the type.
void identify(Base* p){
	std::cout<<Y<<"Identify by pointer"<<W<<std::endl;
	if (dynamic_cast<A*>(p))
		std::cout<<"The type is A"<<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout<<"The type is B"<<std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout<<"The type is C"<<std::endl;
	else
		std::cout<<"I don't know the type, sorry"<<std::endl;
}

// References can not be null. Dynamic_cast will return null if fails.
// So in this case trying to asign a null to a reference will throw an exception.
// Thats why we have to catch them.
void identify(Base& p){
	std::cout<<Y<<"Identify by reference"<<W<<std::endl;
	try{
		A& a = dynamic_cast<A&>(p);
		std::cout<<"is type A"<<std::endl;
		(void)a;
	}catch(std::exception &e){}
	try{
		B& b = dynamic_cast<B&>(p);
		std::cout<<"is type B"<<std::endl;
		(void)b;
	}catch(std::exception &e){}
	try{
		C& c = dynamic_cast<C&>(p);
		std::cout<<"is type C"<<std::endl;
		(void)c;
	}catch(std::exception &e){}
}

Base * generate(void){
	Base * randomClass;
	int randomStuff = getRandomNumber();
	switch (randomStuff)
	{
		case 1:
			randomClass = new A();
			break;
		case 2:
			randomClass = new B();
			break;
		case 3:
			randomClass = new C();
			break;
		default:
			randomClass = NULL;
	}
	return randomClass;
}