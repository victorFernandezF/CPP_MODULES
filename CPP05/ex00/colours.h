/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:55:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/22 12:04:18 by victofer         ###   ########.fr       */
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

# define TEST1 " This test will create a Bureaucrat with a grade \n\
 between 1 abd 150. It shouldn't be any problem\n"

# define TEST2 " Now it creates a bureaucrat with a grade of 180\n\
 Which is not between 1 and 150. It should throw an exception (low)\n"

# define TEST3 " Now it creates a bureaucrat with a valid grade (150)\n\
 Incrementing once should be ok (149). Decrementeing once\n\
 should be ok (150). Decrementing again should throw an exception \n\
 (151 is out of range).\n"

#endif