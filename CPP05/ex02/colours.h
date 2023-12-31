/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:55:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/22 12:37:36 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
# define COLOURS_H

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

# define TEST1 " This test creates a [bureaucrat] with grade 145 and a \n\
 [ShrubberyCreationForm]{sign grade: 145; execution grade 138}.\n So Bureaucrat\
 has enough grade to sign the form but not to execute it.\n\
 At least for now.\n"

# define TEST2 " This test creates a [bureaucrat] with grade 1 and a \n\
 [RobotomyRequestForm]{sign grade: 72; execution grade 45}.\n Bureaucrat\
 has the highest grade possible so is able\n\
 to do everything. Except execute a form which is not signed.\n"

# define TEST3 " This test creates 2 [bureaucrats] with grade 70 and 27 respectively \n\
 and a [PresidentialPardonForm]{(sign grade: 72; execution grade 45}.\n Bureaucrat_1 has enough\
 grade to sign the form but not to execute it. \n Bureaucrat_2 has enought grade to execute it.\n"

#endif