/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:16:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/21 19:04:14 by victofer         ###   ########.fr       */
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
# define R	"\x1B[31m"	// RED
# define G	"\x1B[32m"	// GREEN
# define B	"\x1B[34m"	// BLUE
# define Y	"\x1B[33m"	// YELLOW
# define M	"\x1B[35m"	// MAGENTA
# define C	"\x1B[36m"	// CYAN
# define W	"\x1B[0m"	// WHITE
# define BR	"\x1B[91m"	// BRIGHT RED
# define BG	"\x1B[92m"	// BRIGHT GREEN
# define BB	"\x1B[94m"	// BRIGT BLUE
# define BY	"\x1B[93m"	// BRIGHT YELLOW
# define BM	"\x1B[95m"	// BRIGHT MAGENTA
# define BC	"\x1B[96m"	// BRIGHT CYAN
# define GR	"\x1B[90m" 	// GRAY

// F U N C T I O N S
int is_alpha(std::string str);
int transformIndex(std::string searchIndexStr, int searchIndex);
int checkLimits(int nb);
int checkSearchIndex(std::string str);
#endif

