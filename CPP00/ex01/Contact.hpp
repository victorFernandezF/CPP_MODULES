#include "agenda.hpp"

class Contact {

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    
    public:
        Contact(void);           
        ~Contact(void);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getSecret(void);
        void setFirstName(void);
        void setLastName(void);
        void setNickName(void);
        void setPhoneNumber(void);
        void setSecret(void);
        std::string stringParser(std::string str);
        std::string toString(void);
        void fakestructor(void);
};