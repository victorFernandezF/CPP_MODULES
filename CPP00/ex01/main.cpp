#include "agenda.hpp"

int main(int argc, char const *argv[])
{
    std::string cmd;
    Phonebook phonebook;

    while (1)
    {
        std::cout<<Y<<std::endl<<"Insert a command > "<<W;
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
        else
        {
            std::cout<<R<<"  Command '"<<cmd<<"' not found."<<W<<std::endl;
            std::cout<<"  Commands: ADD SEARCH EXIT."<<std::endl;
        }
    }
    return (0);
}