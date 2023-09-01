/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:55:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/01 10:26:56 by victofer         ###   ########.fr       */
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

# define TEST1 " This is the subject example. It will creates a Cat,\n\
 and a Dog. Then they will be deleted (without leaks).\n"
# define TEST2 " Now we are going to create an array of animals.\n\
 One half will be cats and the other dogs. Then each\n\
 one will be deleted (no leaks)\n"
# define TEST3 " TESTING DEEP COPY. We will create 1 cat.\n\
 Next we will create a second cat which will be a copy of cat 1\n\
 Then we will delete cat 1. If the deep copy works fine cat 2 should\n\
 be ok and no memory errors should appear.\n"
 
#endif