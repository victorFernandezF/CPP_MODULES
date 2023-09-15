/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:55:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/14 18:59:30 by victofer         ###   ########.fr       */
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

# define TEST1 " This is the subject test.\n\
 Creates a Span of five ints.\n Inserts some numbers and displays\n\
 the Shosrtest and longest spans\n"
 
# define TEST2 " Creates a Span of three ints. Inserts three values.\n\
 Then tries to insert some more values. Of course this\n\
 should throw an exception.\n"

# define TEST3 " Lets test the shortestSpan and longestSpan functions.\n\
 Creates a Span and fill it with some values.\n"

# define TEST4 " This will test the addManyNumbers functio. That will\n\
 add N numbers in one call (not by calling addNumbers N times).\n\
 Span values are random and the print is commented in main.cpp in\n\
 order to keep the previous tests visible."

#endif