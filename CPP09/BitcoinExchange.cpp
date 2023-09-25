/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:03:53 by victofer          #+#    #+#             */
/*   Updated: 2023/09/25 19:37:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	(void)copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy){
	(void)copy;
	return (*this);
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::exchange(std::string filename){
	std::ifstream input;
	std::map<std::string, double> map;
	std::ifstream dataBase;
	std::string buffer;
	std::string data = "test.txt";
	std::string tmp;
	std::string tmp_2;
	size_t pos = 0;
	
	(void)filename;
	dataBase.open(data, std::ios::in);
	while (std::getline(dataBase, buffer)){
		pos = buffer.find("|");
		if (pos != std::string::npos){
			tmp = buffer.substr(0, pos);
			tmp_2 = buffer.substr(pos, std::string::npos);
			map[tmp] = strtod(tmp_2.c_str(), NULL);
		}
		for (size_t i = 0; i < map.end(); i++)
			std::cout<<map.first<<" "<<map.second<<std::endl;
		
	}



}