# include "Harl.hpp"

Harl::Harl(void){}
Harl::~Harl(void){}

void Harl::_debug(void){
	std::cout<<std::endl<<G<<"[DEBUG]"<<W<<std::endl
	<<"I love having extra bacon for my "
	<<"7XL-double-cheese-triple-pickle-specialketchup "
	<<"burger. I really do!"
	<<std::endl;
}

void Harl::_info(void){
	std::cout<<std::endl<<B<<"[INFO]"<<W<<std::endl
	<<"I cannot believe adding extra bacon costs more "
	<<"money. You didn't put enough bacon in my burger!"
	<< "If you did, I wouldn't be asking for more!"<<std::endl;
}

void Harl::_warning(void){
	std::cout<<std::endl<<Y<<"[WARNING]"<<W<<std::endl
	<<"I think I deserve to have some extra bacon for "
	<<"free. I've been coming for years whereas you started"
	<<"working here since last month."<<std::endl;
}

void Harl::_error(void){
	std::cout<<std::endl<<R<<"[ERROR]"<<W<<std::endl
	<<"This is unacceptable! I want to speak to the manager now."
	<<std::endl;
}

void Harl::complain(std::string lavel){
	std::string	positions[4] = {"debug", "info", "warning", "error"};
	void (Harl::*funcPtrs[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	for (int i = 0; i < 4; i++)
		if (lavel == positions[i])
			(this->*funcPtrs[i])();
}