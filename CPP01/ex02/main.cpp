/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:09:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 10:15:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colours.h"

int main(void)
{

    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout<<C<<"\nMemory adress of string:    "<<W<<&string<<std::endl;
    std::cout<<BC<<"Memory adress of stringPTR: "<<W<<stringPTR<<std::endl;
    std::cout<<G<<"Memory adress of stringREF: "<<W<<&stringREF<<std::endl;
    std::cout<<std::endl;
    std::cout<<C<<"Value adress of string:    "<<W<<string<<std::endl;
    std::cout<<BC<<"Value adress of stringPTR: "<<W<<*stringPTR<<std::endl;
    std::cout<<G<<"Value adress of stringREF: "<<W<<stringREF<<std::endl;
    std::cout<<std::endl;
    return (0);
}
