/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:55:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/22 12:19:52 by victofer         ###   ########.fr       */
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

# define TEST1 "This test creates a [bureaucrat] with grade 5 and a [form] with \n\
 required grade to sign of 6. Since grade 5 is higher than grade 6, \n\
 bureaucrat will sign the form without problems."

# define TEST2 " This test creates a [bureaucrat] with grade 5 and a [form] with \n\
 required grade to sign of 3. Since grade 5 is lower than grade 6, \n\
 bureaucrat woun't be able to sign the form."

# define TEST3 " This test creates a [bureaucrat] with grade 5 and a [form] with \n\
 required grade to sign of 3. Since grade 5 is lower than grade 3, \n\
 bureaucrat won't be able to sign the form. Then Bureaucrat grade\n\
 will be incremented twice. So, grade now is 3. Bureaucrat now has\n at least\
 the required grade so form will be signed in the second try."

#endif