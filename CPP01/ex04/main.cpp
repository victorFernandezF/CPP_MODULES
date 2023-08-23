/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:51:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 18:41:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "colours.h"

void leaks(void)
{
	std::cout<<W<<"\n___________________________________"<<std::endl;
	std::cout<<M<<" \n-- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex04");
}

std::string searchAndReplace(std::string buffer, std::string search, std::string replace){
	int searchLen;
	int replaceLen;
	int searchPosition;
	
	searchLen = search.length();
	replaceLen = replace.length();
	searchPosition = buffer.find(search);
	while (searchPosition != (int) std::string::npos)
	{
		buffer.erase(searchPosition, searchLen);
		buffer.insert(searchPosition, replace);
		searchPosition = buffer.find(search, searchPosition + replaceLen);
	}
	return buffer;
}

int main(int argc, char **argv)
{
	std::string		filename;
	std::string		search;
	std::string		replace;
	std::string		buffer;
	std::ifstream	input;
	std::ofstream	output;

	atexit(leaks);
	if (argc != 4)
		return (std::cout<<BR<<ARGERROR<<"\n"<<W<<ARGS<<std::endl, 1);
	filename = argv[1];
	search = argv[2];
	replace = argv[3];
	input.open(filename, std::ios::in);
	output.open(filename + ".replace" , std::ios::out);
	if (input.fail() || output.fail())
		return (std::cout<<R<<FILEERROR<<W<<std::endl, 1);
	while (std::getline(input, buffer)){
		buffer = searchAndReplace(buffer, search, replace);
		output<<buffer;
		if (input.peek() != EOF)
			output<<"\n";
	}
	std::cout<<G<<"\nSUCCESS"<<W<<std::endl;
	input.close();
	output.close();
	return 0;
}