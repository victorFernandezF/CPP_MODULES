/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:04:40 by victofer          #+#    #+#             */
/*   Updated: 2023/08/21 19:04:43 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

class Phonebook{
    private:
        Contact _contacts[8];
        int     _index;
        int     _maxContacts;
    
    public:
        Phonebook(void);
        ~Phonebook(void);
        void addContact(void);
        void showListing(void);
        void printIndexSearch(void);
};