#include "agenda.hpp"

// Default Constructor
Phonebook::Phonebook(void){
	this->_index = 0;
	this->_maxContacts = 8;
};

// Destructor
Phonebook::~Phonebook(void){};

// Add a new contact. if there are 8. it will overwrite the older one.
void Phonebook::addContact(Contact contact){
    if (this->_index == this->_maxContacts)
        this->_index = 0;
    this->_contacts[this->_index] = contact;
    this->_index++;
}

// Shows the complete list of existing contacte with an _index.
void    Phonebook::showListing(void){
    for (int i = 0; i < this->_maxContacts; i++)
    {
        if (this->_contacts[i].getFirstName() == "")
            continue;

        std::cout<<std::setw(10)<<B<<i + 1<<W<<'|';
        std::cout<<std::setw(10)<<_contacts[i].stringParser(_contacts[i].getFirstName())<<'|';
        std::cout<<std::setw(10)<<_contacts[i].stringParser(_contacts[i].getLastName())<<'|';
        std::cout<<std::setw(10)<<_contacts[i].stringParser(_contacts[i].getNickName())<<'|'<<std::endl;
    }
}

// Ask an _index and show the contact info for this _index. 
void    Phonebook::printIndexSearch(void){
    std::string search_IndexStr;
    int search_Index;

    std::cout<<std::endl<<B<<"-> Insert an index > "<<W;
    std::getline(std::cin, search_IndexStr);
    search_Index = checkSearchIndex(search_IndexStr);
    std::cout<<std::endl;
    if (this->_contacts[search_Index - 1].getFirstName() == "" || search_Index <= 0 || search_Index == -2)
    {
		if (search_Index == -2)
			return;
		if (search_Index == 0)
            std::cout<<R<<"  * Index must be a number"<<W<<std::endl;
        else if (search_Index == -1)
           std::cout<<R<<"  * Index does not exist"<<W<<std::endl;
        else
           std::cout<<R<<"  * Index "<<search_Index<<" does not exist"<<W<<std::endl<<std::endl;
        this->showListing();
        this->printIndexSearch();
    }
    else
        std::cout<<this->_contacts[search_Index - 1].toString()<<std::endl;
}