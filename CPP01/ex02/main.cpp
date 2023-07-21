#include <iostream>

int main(void)
{

    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout<<"Memory adress of string:    "<<&string<<std::endl;
    std::cout<<"Memory adress of stringPTR: "<<stringPTR<<std::endl;
    std::cout<<"Memory adress of stringREF: "<<&stringREF<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Value adress of string:    "<<string<<std::endl;
    std::cout<<"Value adress of stringPTR: "<<*stringPTR<<std::endl;
    std::cout<<"Value adress of stringREF: "<<stringREF<<std::endl;
    return (0);
}
