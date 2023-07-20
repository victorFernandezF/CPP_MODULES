#ifndef AGENDA_HPP
# define AGENDA_HPP
# include <iostream>
# include <iomanip>
# include "contact.hpp"
# include "phonebook.hpp"

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

int is_alpha(std::string str);
int transformIndex(std::string searchIndexStr, int searchIndex);
int checkLimits(int nb);
int checkSearchIndex(std::string str);
#endif

