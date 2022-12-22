#include <iostream>
#include <string>
#include "Contact.class.hpp"

using std::string;

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

std::string truncate(std::string str) {
    if (str.length() < 10) {
        return (std::string(10 - str.length(), ' ') + str);
    } else {
        str[9] = '.';
        return (str.substr(0, 10));
    }
}

void    Contact::displayShort(void) {
    std::cout << truncate(_first_name) + "|" \
                << truncate(_last_name) + "|" \
                << truncate(_nickname) + "|"\
                << std::endl;
}


void    Contact::displayFull(void) {
    std::cout << "FIRST NAME: " << _first_name << std::endl;
    std::cout << "LAST NAME: " << _last_name << std::endl;
    std::cout << "NICK NAME: " << _nickname << std::endl;
    std::cout << "PNONE NUMBER: " << _phone_number << std::endl;
    std::cout << "DARKEST SECRET: " << _darkest_secret << std::endl;
}

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

void Contact::setFirstName(string val)
{
    _first_name = val;
}

void Contact::setLastName(string val)
{
    _last_name = val;
}

void Contact::setNickName(string val)
{
    _nickname = val;
}

void Contact::setPhoneNumber(string val)
{
    _phone_number = val;
}

void Contact::setDarkestSecret(string val)
{
    _darkest_secret = val;
}

void    Contact::Edit(void) {
    int i;

    string first_name = get_input("FIRST NAME: ");
    string last_name = get_input("LAST NAME: ");
    string nickname = get_input("NICKNAME: ");
    string phone_number;
    while (1) {
        i = -1;
        phone_number = get_input("PHONE NUMBER: ");
        while (phone_number[++i]) {
            if (!std::isdigit(phone_number[i])) {
                std::cout << "Error: phone number must be a numeric" << std::endl;
                phone_number.clear();
                break;
            }
        }
        if (phone_number.length() != 0)
            break;
    }
    string darkest_secret = get_input("DARKEST SECRET: ");
    _first_name = first_name;
    _last_name = last_name;
    _nickname = nickname;
    _phone_number = phone_number;
    _darkest_secret = darkest_secret;
}