/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/09/06 18:52:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "Serializer.hpp"
#include <iostream>
#include <stdlib.h>

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex01");
}

int main(void)
{
	atexit(leaks);
	Data *ptr = new Data;
	uintptr_t result;
	Data *res;
	
	ptr->a = 14;
	ptr->b = '*';
	ptr->c = 42.5f;
	
	std::cout<<Y<<"Initial datas of the struct"<<W<<std::endl;
	std::cout<<C<<"a: "<<W<<ptr->a<<"\n";
	std::cout<<C<<"b: "<<W<<ptr->b<<"\n";
	std::cout<<C<<"c: "<<W<<ptr->c<<"\n\n";
	
	std::cout<<Y<<"Convert Struct to uintptr_t"<<W<<std::endl;
	result = Serializer::serialize(ptr);
		
	std::cout<<C<<"converted struct: "<<W<<result<<"\n";
	std::cout<<C<<"Converting uintptr_t to struct: \n";
	res = Serializer::deserialize(result);
	
	std::cout<<Y<<"\nDatas of the struct after being deserialized"<<W<<std::endl;
	std::cout<<C<<"a: "<<W<<res->a<<"\n";
	std::cout<<C<<"b: "<<W<<res->b<<"\n";
	std::cout<<C<<"c: "<<W<<res->c<<"\n";
	
	delete ptr;
	return 0;
}
