/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:03:59 by victofer          #+#    #+#             */
/*   Updated: 2023/08/21 19:04:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

int main(void)
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
            phonebook.addContact();
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