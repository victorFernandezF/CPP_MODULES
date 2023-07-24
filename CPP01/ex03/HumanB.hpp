#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(void);
		~HumanB(void);
		void attack(void);
};

#endif