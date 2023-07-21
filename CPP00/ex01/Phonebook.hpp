#include "agenda.hpp"

class Phonebook{
    private:
        Contact contacts[8];
        int     index = 0;
        int     max_contacts = 8;
    
    public:
        Phonebook(void);
        ~Phonebook(void);
        void addContact(Contact contact);
        void showListing(void);
        void printIndexSearch(void);
};