/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:08:08 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:07:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
#include "colours.h"

class Zombie{
    private:
        std::string _name;
    public:
        Zombie(void);
        ~Zombie(void);
        void announce(void);
        void setName(std::string name);
};
#endif