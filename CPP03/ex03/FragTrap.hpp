/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:59:23 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 18:18:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"


class FragTrap: virtual public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &copy);	
		FragTrap &operator=(const FragTrap &copy);
		~FragTrap();
		void highFivesGuys(void);
		void attack(const std::string& target);
};

#endif