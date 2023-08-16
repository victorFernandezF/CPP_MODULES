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
void Contact::setFirstName(void){
    std::cout<<G<<" First Name: "<<W;
    std::getline(std::cin, this->_firstName);
    if (this->_firstName == "")
    {
        std::cout<<R<<"     *First name can not be null*"<<W<<std::endl;
        this->setFirstName();
    }
}
void Contact::setLastName(void){
    std::cout<<G<<" Last Name: "<<W;
    std::getline(std::cin, this->_lastName);
    if (this->_lastName == "")
    {
        std::cout<<R<<"     *Last name can not be null*"<<W<<std::endl;
        this->setLastName();
    }
}
void Contact::setNickName(void){
    std::cout<<G<<" Nick Name: "<<W;
    std::getline(std::cin, this->_nickName);
    if (this->_nickName == "")
    {
        std::cout<<R<<"     *Nick name can not be null*"<<W<<std::endl;
        this->setNickName();
    }
}
void Contact::setPhoneNumber(void){
    std::cout<<G<<" Phone number: "<<W;
    std::getline(std::cin, this->_phoneNumber);
    if (this->_phoneNumber == "")
    {
        std::cout<<R<<"     *Phone number can not be null*"<<W<<std::endl;
        this->setPhoneNumber();
    }
}
void Contact::setSecret(void){
    std::cout<<G<<" Darkest Secret: "<<W;
    std::getline(std::cin, this->_darkestSecret);
    if (this->_darkestSecret == "")
    {
        std::cout<<R<<"     *Darkest secret can not be null*"<<W<<std::endl;
        this->setSecret();
    }
}
void Contact::fillContacts(void){
    this->setFirstName();
    this->setLastName();
    this->setNickName();
    this->setPhoneNumber();
    this->setSecret();
}

// Cuts strings longer	than 10 chars and add a dot at the end.
std::string Contact::stringParser(std::string str){
    if (str.length() < 10)
        return (str);
    return (str.substr(0, 9) + '.');
}

// Return a well formated string ready to be printed. (search result)
std::string Contact::toString(void){
    return ("\x1B[32mFirst name:\x1B[0m " + this->getFirstName() + "\n"+
     "\x1B[32mLast name:\x1B[0m " + this->getLastName() + "\n"+
     "\x1B[32mNick name:\x1B[0m " + this->getNickName() + "\n"+
     "\x1B[32mPhone number:\x1B[0m " + this->getPhoneNumber() + "\n"+
     "\x1B[32mDarkest secret:\x1B[0m " + this->getSecret() + "\n");
}
