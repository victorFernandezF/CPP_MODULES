/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:16:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 10:17:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AGENDA_HPP
# define AGENDA_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include "Phonebook.hpp"

// C O L O R
# define R	"\x1B[31m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define BB	"\x1B[94m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"
# define W	"\x1B[0m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"

// F U N C T I O N S
int is_alpha(std::string str);
int transformIndex(std::string searchIndexStr, int searchIndex);
int checkLimits(int nb);
int checkSearchIndex(std::string str);
#endif

