#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <iomanip>

// COLOR
# define R	"\x1B[31m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define BB	"\x1B[94m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"
# define W	"\x1B[0m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"

class Harl{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string lavel);
};

#endif