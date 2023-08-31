/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:45:31 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 12:54:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
# include "colours.h"

class Converter{
	private:
		static char _char;
		static int	_int;
		static float _float;
		static double _double;
				
	public:
		Converter();
		Converter(const Converter &copy);
		Converter &operator=(const Converter &copy);
		~Converter();
		
		void Convert(std::string);
};

#endif