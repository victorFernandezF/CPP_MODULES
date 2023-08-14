#include "agenda.hpp"

class Phonebook{
    private:
        Contact _contacts[8];
        int     _index;
        int     _maxContacts;
    
    public:
        Phonebook(void);
        ~Phonebook(void);
        void addContact(Contact contact);
        void showListing(void);
        void printIndexSearch(void);
};