/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:57:46 by victofer          #+#    #+#             */
/*   Updated: 2023/09/28 13:54:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BICTOINEXCHANGE_HPP
# define BICTOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include "colours.h"

class BitcoinExchange{
	private:
		std::map<std::string, double>_database;
		void 	_openFile(std::ifstream file, std::string filename);
		int		_checkValues(std::string key, std::string value);
		int		_checkDate(std::string key);
		void	_printResult(std::string key,std::string value);
		std::string _checkIfKeyExists(std::string key);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();
		void exchange(std::string filename);

		class UserFileNotFound;
		class DataBaseNotFound;
};

#endif