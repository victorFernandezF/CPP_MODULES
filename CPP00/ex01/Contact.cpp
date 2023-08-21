#include "agenda.hpp"

Contact::Contact(void){}
Contact::~Contact(void){}

// GETTERS
std::string Contact::getFirstName(void){
    return (_firstName);
}
std::string Contact::getLastName(void){
    return (_lastName);
}
std::string Contact::getNickName(void){
    return (_nickName);
}
std::string Contact::getPhoneNumber(void){
    return (_phoneNumber);
}
std::string Contact::getSecret(void){
    return (_darkestSecret);
}

// SETTERS
std::string Contact::_askFirstName(void){
    std::string first;
	std::cout<<G<<" First Name: "<<W;
    std::getline(std::cin, first);
	return first;
}
std::string Contact::_askLastName(void){
    std::string first;
	std::cout<<G<<" Last Name: "<<W;
    std::getline(std::cin, first);
	return first;
}
std::string Contact::_askNickName(void){
    std::string first;
	std::cout<<G<<" Nick Name: "<<W;
    std::getline(std::cin, first);
	return first;
}
std::string Contact::_askPhoneNumber(void){
    std::string first;
	std::cout<<G<<" Phone Number: "<<W;
    std::getline(std::cin, first);
	return first;
}
std::string Contact::_askSecret(void){
    std::string first;
	std::cout<<G<<" Darkest Secret: "<<W;
    std::getline(std::cin, first);
	return first;
}
void Contact::fillContacts(void){
    std::string first = this->_askFirstName();
    std::string last = this->_askLastName();
    std::string nick = this->_askNickName();
    std::string phone = this->_askPhoneNumber();
   	std::string secret =  this->_askSecret();
	if (first == "" || last == "" || nick == ""
		|| phone == "" || secret == "")
	{
		std::cout<<R<<"Every field must be filled."<<std::endl;
		return ;
	}
	this->_firstName = first;
	this->_lastName = last;
	this->_nickName = nick;
	this->_phoneNumber = phone;
	this->_darkestSecret = secret;
}

// Cuts strings longer	than 10 chars and add a dot at the end.
std::string Contact::stringParser(std::string str){
    if (str.length() < 10)
        return (str);
    return (str.substr(0, 9) + '.');
}

// Return a well formated string ready to be printed. (search result)
std::string Contact::toString(void){
    return ("\n\x1B[32mFirst name:\x1B[0m " + this->getFirstName() + "\n"+
     "\x1B[32mLast name:\x1B[0m " + this->getLastName() + "\n"+
     "\x1B[32mNick name:\x1B[0m " + this->getNickName() + "\n"+
     "\x1B[32mPhone number:\x1B[0m " + this->getPhoneNumber() + "\n"+
     "\x1B[32mDarkest secret:\x1B[0m " + this->getSecret() + "\n");
}
