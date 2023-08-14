/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:33:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 12:35:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

# define R	"\x1B[31m"
# define GR	"\x1B[90m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define BB	"\x1B[94m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"
# define W	"\x1B[0m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"
# define BR	"\x1B[0;95m"

class Brain{
	protected:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(Brain &copy);	
		Brain &operator=(const Brain &copy);	
		virtual ~Brain();
};
#endif