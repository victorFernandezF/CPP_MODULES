#include "agenda.hpp"

Contact addNewContact()
{
    std::string first;
    std::string last;
    std::string nick;
    std::string secret;
    std::string number;
    
    std::cout<<"First Name: ";
    std::getline(std::cin, first);
    std::cout<<"Last Name: ";
    std::getline(std::cin, last);
    std::cout<<"Nick Name: ";
    std::getline(std::cin, nick);
    std::cout<<"phone Number: ";
    std::getline(std::cin, number);
    std::cout<<"Secret: ";
    std::getline(std::cin, secret);
    Contact contact(first, last, nick, number, secret);
    return (contact);
}

void searchContact()
{

}