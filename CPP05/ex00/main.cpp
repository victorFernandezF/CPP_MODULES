/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/22 12:53:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void leaks(void)
{
	std::cout<<M<<"\n -- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

int main(void)
{
	atexit(leaks);
	std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
	<<BB<<" We will create a Bureaucrat named 'pepe' with a grade "<<std::endl
	<<" between 1 abd 150. It shouldn't be any problem"<<W<<std::endl<<std::endl;
	{
		Bureaucrat buro("pepe", 27);
		std::cout<<buro.getName()<<"'s grade: "
		<<buro.getGrade()<<std::endl;
	}
	
	std::cout<<std::endl
	<<"___________________________________"<<std::endl
	<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST 2] -- ◉"<<std::endl
	<<BB<<" Now we will try to create a bureaucrat with a grade "<<std::endl
	<<" that is not between 1 and 150. It should throw an exception"<<W<<std::endl<<std::endl;
	{
		Bureaucrat buro("pepe", 180);
		std::cout<<buro.getName()<<"'s grade: "
		<<buro.getGrade()<<std::endl;
	}
	return 0;
}
