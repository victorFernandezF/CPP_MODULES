#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA{
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA(std::string hName, Weapon &weapon);
		~HumanA(void);
		void attack(void);
};

#endif