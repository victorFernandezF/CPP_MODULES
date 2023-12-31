/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:04:19 by victofer          #+#    #+#             */
/*   Updated: 2023/08/21 19:10:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

class Contact {

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
		std::string _askFirstName(void);
        std::string _askLastName(void);
        std::string _askNickName(void);
        std::string _askPhoneNumber(void);
        std::string _askSecret(void);

    public:
        Contact(void);           
        ~Contact(void);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getSecret(void);
		std::string stringParser(std::string str);
        int fillContacts(void);
		std::string toString(void);
};