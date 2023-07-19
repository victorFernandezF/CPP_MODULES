#include "agenda.hpp"

Phonebook::Phonebook(void){};
Phonebook::~Phonebook(void){};

void Phonebook::addContact(Contact contact){
    if (this->index == this->max_contacts)
        this->index = 0;
    this->contacts[this->index] = contact;
    this->index++;
}
void Phonebook::test(void){
    for (size_t i = 0; i < this->max_contacts; i++)
        std::cout<<this->contacts[i].getFirstName()<<std::endl;    
}

void    Phonebook::showListing(void){
    for (size_t i = 0; i < this->max_contacts; i++)
    {
        if (this->contacts[i].getFirstName() == "")
            continue;
        std::cout<<std::setw(10);
        std::cout<<i + 1<<'|';
        std::cout<<contacts[i].stringParser(contacts[i].getFirstName())<<'|';
        std::cout<<contacts[i].stringParser(contacts[i].getLastName())<<'|';
        std::cout<<contacts[i].stringParser(contacts[i].getNickName())<<'|'<<std::endl;
    }
}

void    Phonebook::printIndexSearch(void){
    std::string searchIndexStr;
    int searchIndex;


    std::cout<<std::endl<<"Insert an index > ";
    std::getline(std::cin, searchIndexStr);
    std::cout<<std::endl;
    searchIndex = std::stoi(searchIndexStr);
    if (this->contacts[searchIndex - 1].getFirstName() == "")
    {
        std::cout<<"Index "<<searchIndex <<" does not exist"<<std::endl;
        this->showListing();
        this->printIndexSearch();
    }
    else
        std::cout<<this->contacts[searchIndex - 1].toString()<<std::endl;
}