#include "agenda.hpp"

Phonebook::Phonebook(void){
	this->index = 0;
	this->maxContacts = 8;
};

Phonebook::~Phonebook(void){};

void Phonebook::addContact(Contact contact){
    if (this->index == this->maxContacts)
        this->index = 0;
    this->contacts[this->index] = contact;
    this->index++;
}

void    Phonebook::showListing(void){
    for (size_t i = 0; i < this->maxContacts; i++)
    {
        if (this->contacts[i].getFirstName() == "")
            continue;

        std::cout<<std::setw(10)<<B<<i + 1<<W<<'|';
        std::cout<<std::setw(10)<<contacts[i].stringParser(contacts[i].getFirstName())<<'|';
        std::cout<<std::setw(10)<<contacts[i].stringParser(contacts[i].getLastName())<<'|';
        std::cout<<std::setw(10)<<contacts[i].stringParser(contacts[i].getNickName())<<'|'<<std::endl;
    }
}

void    Phonebook::printIndexSearch(void){
    std::string searchIndexStr;
    int searchIndex;
    int flag;

    std::cout<<std::endl<<B<<"-> Insert an index > "<<W;
    std::getline(std::cin, searchIndexStr);
    searchIndex = checkSearchIndex(searchIndexStr);
    std::cout<<std::endl;
    if (this->contacts[searchIndex - 1].getFirstName() == "" || searchIndex <= 0)
    {
        if (searchIndex == 0)
            std::cout<<R<<"  *Index must be a number"<<W<<std::endl<<std::endl;
        else if (searchIndex == -1)
           std::cout<<R<<"  *Index does not exist"<<W<<std::endl<<std::endl;
        else
           std::cout<<R<<"  *Index "<<searchIndex<<" does not exist"<<W<<std::endl<<std::endl;
        this->showListing();
        this->printIndexSearch();
    }
    else
        std::cout<<this->contacts[searchIndex - 1].toString()<<std::endl;
}