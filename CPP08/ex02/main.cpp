/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 10:42:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>
#include "colours.h"
#include "MutantStack.hpp"

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex02");
}

void printTestHeaders(int nbTest, std::string testHeader, int newLine){
	if (newLine == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<nbTest<<"] -- ◉"<<std::endl
	<<BB<<testHeader<<W<<std::endl;
}

int main(void)
{
	atexit(leaks);
	printTestHeaders(1, TEST1, 0);
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	printTestHeaders(2, TEST2, 0);
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}
	printTestHeaders(3, TEST3, 0);
	{
		MutantStack<int> stack;
		std::deque<int>::iterator it;
		int i = -1;

		while (++i < 5){
			stack.push(i);
			std::cout<<"stack.push("<<i<<")\n";
		}
		std::cout<<C<<"\n * Iterate stack printing its members\n"<<W;
		it = stack.begin();
		while (it != stack.end()){
			std::cout<<*it<<std::endl;
			it++;
		}
	}
	printTestHeaders(4, TEST4, 0);
	{
		MutantStack<int> stack;
		std::deque<int>::iterator it;
		int i = -1;

		while (++i < 5){
			stack.push(i);
			std::cout<<"stack.push("<<i<<")\n";
		}
		it = stack.begin();
		while (it != stack.end()){
			*it += 42; 
			it++;
		}
		std::cout<<C<<"\n * Iterate stack adding 42 to each element\n"<<W;
		it = stack.begin();
		while (it != stack.end()){
			std::cout<<*it<<std::endl;
			it++;
		}	
	}
	return 0;
}
