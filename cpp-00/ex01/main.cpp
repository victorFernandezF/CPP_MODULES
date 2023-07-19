#include "agenda.hpp"

int main(int argc, char const *argv[])
{
    std::string cmd;
    std::string searchIndex;
    Phonebook phonebook;


    while (1)
    {
        std::cout<<"Insert a command > ";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT" || cmd == "exit")
            return (0);
        if (cmd == "ADD" || cmd == "add")
        {
            Contact contact;
            contact.fakestructor();
            phonebook.addContact(contact);
        }
        else if (cmd == "SEARCH" || cmd == "search") {
            phonebook.showListing();
            phonebook.printIndexSearch();
        }
        else if (cmd == "TEST" || cmd == "test") {

            phonebook.test();
        }
        else
        {
            std::cout<<std::endl<<"Command '"<<cmd<<"' not found."<<std::endl;
            std::cout<<"Commands: ADD SEARCH EXIT."<<std::endl<<std::endl;
        }
    }
    return (0);
}