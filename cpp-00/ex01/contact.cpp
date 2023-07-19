#include "agenda.hpp"

Contact::Contact(void){}
Contact::~Contact(void){}

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

void Contact::setFirstName(void){
    std::cout<<"First Name: ";
    std::getline(std::cin, this->_firstName);
    if (this->_firstName == "")
    {
        std::cout<<"First name can not be null"<<std::endl;
        this->setFirstName();
    }
}
void Contact::setLastName(void){
    std::cout<<"Last Name: ";
    std::getline(std::cin, this->_lastName);
    if (this->_lastName == "")
    {
        std::cout<<"Last name can not be null"<<std::endl;
        this->setLastName();
    }
}
void Contact::setNickName(void){
    std::cout<<"Nick Name: ";
    std::getline(std::cin, this->_nickName);
    if (this->_nickName == "")
    {
        std::cout<<"Nick name can not be null"<<std::endl;
        this->setNickName();
    }
}
void Contact::setPhoneNumber(void){
    std::cout<<"Phone number: ";
    std::getline(std::cin, this->_phoneNumber);
    if (this->_phoneNumber == "")
    {
        std::cout<<"Phone number can not be null"<<std::endl;
        this->setPhoneNumber();
    }
}
void Contact::setSecret(void){
    std::cout<<"Darkest Secret: ";
    std::getline(std::cin, this->_darkestSecret);
    if (this->_darkestSecret == "")
    {
        std::cout<<"Darkest secret can not be null"<<std::endl;
        this->setSecret();
    }
}

void Contact::fakestructor(void){
    this->setFirstName();
    this->setLastName();
    this->setNickName();
    this->setPhoneNumber();
    this->setSecret();
    //std::getline(std::cin, this->_firstName);

}

std::string Contact::stringParser(std::string str){
    if (str.length() < 10)
        return (str);
    return (str.substr(0, 9) + '.');
}

std::string Contact::toString(void){
    return ("First name: " + this->getFirstName() + "\n"+
     "Last name: " + this->getLastName() + "\n"+
     "Nick name: " + this->getNickName() + "\n"+
     "Phone number: " + this->getPhoneNumber() + "\n"+
     "Darkest secret: " + this->getSecret() + "\n");
}
