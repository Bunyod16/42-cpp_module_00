#include <iostream>
#include <string>
#include "Contact.class.hpp"

std::string get_input(std::string prompt) {
    std::string input;

    input = "";
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::strlen(input.c_str()) != 0)
            break;
        else
            std::cout << "FIELD CANNOT BE EMPTY" << std::endl;
    }
    return (input);
}

void    Contact::Edit(void) {
    int i;

    this->first_name = get_input("FIRST NAME: ");
    this->last_name = get_input("LAST NAME: ");
    this->nickname = get_input("NICKNAME: ");
    while (1) {
        i = -1;
        this->phone_number = get_input("PHONE NUMBER: ");
        while (this->phone_number[++i]) {
            if (!std::isdigit(this->phone_number[i])) {
                break ;
            }
        }
        if (!std::isdigit(this->phone_number[i])) {
            std::cout << "Error: phone number must be a numeric" << std::endl;
            this->phone_number.clear();
        } else {
            break;
        }
    }
    this->darkest_secret = get_input("DARKEST SECRET: ");
}

std::string truncate(std::string str) {
    if (str.length() < 10) {
        return (std::string(10 - str.length(), ' ') + str);
    } else {
        str[9] = '.';
        return (str.substr(0, 10));
    }
}

void    Contact::displayShort(void) {
    std::cout << truncate(this->first_name) + "|" \
                << truncate(this->last_name) + "|" \
                << truncate(this->nickname) + "|"\
                << std::endl;
}


void    Contact::displayFull(void) {
    std::cout << "FIRST NAME: " << this->first_name << std::endl;
    std::cout << "LAST NAME: " << this->last_name << std::endl;
    std::cout << "NICK NAME: " << this->nickname << std::endl;
    std::cout << "PNONE NUMBER: " << this->phone_number << std::endl;
    std::cout << "DARKEST SECRET: " << this->darkest_secret << std::endl;

using std::string;

Contact::Contact(string fname, string lname, string nname, string pnum, string dsecret) : _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(pnum), _darkest_secret(dsecret) {}

Contact::Contact(const Contact &copy) {
    _first_name = copy._first_name;
    _last_name = copy._last_name;
    _nickname = copy._nickname;
    _phone_number = copy._phone_number;
    _darkest_secret = copy._darkest_secret;
}

Contact::~Contact(void) {
}

string Contact::getFirstName()
{
    return (_first_name);
}

string Contact::getLastName()
{
    return (_last_name);
}

string Contact::getNickName()
{
    return (_nickname);
}

string Contact::getPhoneNumber()
{
    return (_phone_number);
}

string Contact::getDarkestSecret()
{
    return (_darkest_secret);
}
