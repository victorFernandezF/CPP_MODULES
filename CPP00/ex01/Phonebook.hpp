#include "agenda.hpp"

class Phonebook{
    private:
        Contact contacts[8];
        int     index;
        int     maxContacts;
    
    public:
        Phonebook(void);
        ~Phonebook(void);
        void addContact(Contact contact);
        void showListing(void);
        void printIndexSearch(void);
};