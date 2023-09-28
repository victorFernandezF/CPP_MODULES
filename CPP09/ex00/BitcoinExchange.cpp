/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:03:53 by victofer          #+#    #+#             */
/*   Updated: 2023/09/28 18:37:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// E X C E P T I O N S
class BitcoinExchange::UserFileNotFound : public std::exception{
	public: virtual char *what() const throw(){
		return (char *)("Error: file not found.");
	}
};

class BitcoinExchange::DataBaseNotFound : public std::exception{
	public: virtual char *what() const throw(){
		return (char *)("Error: Database file not found.");
	}
};

// C O N S T R U C T O R S
BitcoinExchange::BitcoinExchange(): _dbName("data.csv"){
	std::ifstream dataBase;
	std::string buffer;
	std::string key;
	std::string value;

	dataBase.open(this->_dbName, std::ios::in);
	if (dataBase.fail())
		throw DataBaseNotFound();
	while (std::getline(dataBase, buffer)){
		if (buffer.find(",") != std::string::npos){
			key = buffer.substr(0, buffer.find(","));
			value = buffer.substr(buffer.find(",") + 1, std::string::npos);
			this->_database[key] = strtod(value.c_str(), NULL);
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	std::ifstream dataBase;
	std::string buffer;
	std::string key;
	std::string value;
	
	this->_dbName = copy._dbName;
	dataBase.open(this->_dbName, std::ios::in);
	if (dataBase.fail())
		throw DataBaseNotFound();
	while (std::getline(dataBase, buffer)){
		if (buffer.find(",") != std::string::npos){
			key = buffer.substr(0, buffer.find(","));
			value = buffer.substr(buffer.find(",") + 1, std::string::npos);
			this->_database[key] = strtod(value.c_str(), NULL);
		}
	}
}	

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy){
	std::ifstream dataBase;
	std::string buffer;
	std::string key;
	std::string value;
	
	this->_dbName = copy._dbName;
	dataBase.open(this->_dbName, std::ios::in);
	if (dataBase.fail())
		throw DataBaseNotFound();
	while (std::getline(dataBase, buffer)){
		if (buffer.find(",") != std::string::npos){
			key = buffer.substr(0, buffer.find(","));
			value = buffer.substr(buffer.find(",") + 1, std::string::npos);
			this->_database[key] = strtod(value.c_str(), NULL);
		}
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

// O T H E R   F U N C T I O N S

// Checks if date is well formated (yyyy-mm-dd)
int BitcoinExchange::_checkDate(std::string key){
	std::string year;
	std::string month;
	std::string day;
	std::string rest;
	
	year = key.substr(0, key.find('-'));
	rest = key.substr(key.find('-') + 1, std::string::npos);
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

/*Check if date exist in database. If not, returns the inmediately
  lower date which exists in db.
*/
std::string BitcoinExchange::_checkIfKeyExists(std::string key){
	(void) key;
	std::map<std::string, double> mymap = this->_database;
	std::map<std::string,double>::iterator itlow,it;
	if (mymap.find(key) != mymap.end())
		return key;
	itlow=mymap.lower_bound(key);
	itlow--;
	return itlow->first;
}

// Checks if values are valid. (positives, and between 0 and 100)
int BitcoinExchange::_checkValues(std::string key, std::string value){
	if (value[0] == '-')
		std::cout<<"Error: not a positive number."<<std::endl;
	else if (value.size() > 3)
		std::cout<<"Error: too large number."<<std::endl;
	else if (this->_checkDate(key) == 1)
		std::cout<<"Error: bad input => "<<key<<std::endl;
	else if (value.empty())
		std::cout<<"Error: no value"<<std::endl;
	else {
		return 0;
	}
	return 1;
}

// Prints the result of exchanging the values.
void BitcoinExchange::_printResult(std::string key, std::string value){
	double result;
	key = this->_checkIfKeyExists(key);
	result = this->_database[key] * strtod(value.c_str(), NULL);
	std::cout<<key<<" => "<<value<<" = ";
	std::cout<<result<<std::endl;
}

// Main function.
void BitcoinExchange::exchange(std::string filename){
	std::ifstream input;
	std::string buffer;
	std::string key;
	std::string value;

	input.open(filename, std::ios::in);
	if (input.fail())
		throw UserFileNotFound();
	while (std::getline(input, buffer)){
		if (buffer.find("|") != std::string::npos){
			key = buffer.substr(0, buffer.find("|") - 1);
			value = buffer.substr(buffer.find("|") + 2, std::string::npos);	
		}
		else{
			key = buffer.substr(0, std::string::npos);
			value = "";
		}
		if (value == "value")
			continue;
		if (this->_checkValues(key, value) == 0)
			this->_printResult(key, value);
	}
}