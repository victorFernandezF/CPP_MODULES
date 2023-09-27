/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:03:53 by victofer          #+#    #+#             */
/*   Updated: 2023/09/27 19:32:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//EXCEPTIONS
class BitcoinExchange::FileNotFoundException : public std::exception{
	public: virtual char *what() const throw(){
		return (char *)("Error: file not found.");
	}
};

BitcoinExchange::BitcoinExchange(){
	std::ifstream dataBase;
	std::string buffer;
	std::string data = "data.csv";
	std::string key;
	std::string value;
	size_t pos = 0;
	

	dataBase.open(data, std::ios::in);
	if (dataBase.fail())
		throw FileNotFoundException();
	while (std::getline(dataBase, buffer)){
		pos = buffer.find(",");
		if (pos != std::string::npos){
			key = buffer.substr(0, pos);
			value = buffer.substr(pos + 1, std::string::npos);
			this->_database[key] = strtod(value.c_str(), NULL);
		}
	}
}

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
	std::string buffer;
	std::string key;
	std::string value;
	size_t pos = 0;
	
	input.open(filename, std::ios::in);
	while (std::getline(input, buffer)){
		pos = buffer.find("|");
		if (pos != std::string::npos){
			key = buffer.substr(0, pos - 1);
			value = buffer.substr(pos + 2, std::string::npos);	
		}
		else{
			key = buffer.substr(0, std::string::npos);
			value = "";
		}
		this->_checkValues(key, value);
	}
	//std::cout<<C<<this->_database.at("2029-01-02")<<W<<"\n";
}


int BitcoinExchange::_checkDate(std::string key){
	std::string year;
	std::string month;
	std::string day;
	std::string rest;
	size_t pos = key.find('-');
	
	year = key.substr(0, pos);
	rest = key.substr(pos + 1, std::string::npos);
	month = rest.substr(0, rest.find('-'));
	rest = key.substr(rest.find('-'), std::string::npos);
	day = rest.substr(0, rest.find('-'));
	if (year.size() != 4)
		return 1;
	if (month.size() != 2 || strtod(month.c_str(), NULL) > 12)
		return 1;
	if (month.size() != 2 || strtod(day.c_str(), NULL) > 31)
		return 1;
	return 0;
}

std::string BitcoinExchange::_checkIfKeyExists(std::string key){
	(void) key;
	std::map<std::string, double> mymap = this->_database;
	std::map<std::string,double>::iterator itlow,it;
	if (mymap.find(key) != mymap.end())
		return key;
	itlow=mymap.lower_bound(key);
	if(!mymap.count(key))
		itlow--;
	return itlow->first;
}

void BitcoinExchange::_checkValues(std::string key, std::string value){
	double result;
	if (value[0] == '-')
		std::cout<<"Error: not a positive number."<<std::endl;
	else if (value.size() > 3)
		std::cout<<"Error: too large number."<<std::endl;
	else if (this->_checkDate(key) == 1)
		std::cout<<"Error: bad input => "<<key<<std::endl;
	else if (value.empty())
		std::cout<<"Error: no value"<<std::endl;
	else {
		key = this->_checkIfKeyExists(key);
		result = this->_database[key] * strtod(value.c_str(), NULL);
		std::cout<<key<<" => "<<value<<" = ";
		std::cout<<result<<std::endl;
	}
}
