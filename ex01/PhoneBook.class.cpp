#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _total_contacts(0) {}

void    PhoneBook::addContact(int id, char *first_name, char *last_name, char *nickname, char *phone_number, char *darkest_secret) {
    this->contacts[id].AddInfo(first_name, last_name, nickname, phone_number, darkest_secret);
    this->_total_contacts++;
}

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

void rotate_array(Contact *contacts) {
    int i;
    Contact temp;

    i = 0;
    temp = contacts[7];
    while (i < 8) {
        contacts[i] = contacts[i + 1];
    }
    contacts[0] = temp;
}

void    PhoneBook::search(void) {
    std::string     input;
    Contact         contact;

    if (this->_total_contacts == 8) {
        rotate_array(this->contacts);
        contact = this->contacts[0];
    }
    else {
        contact = this->contacts[_total_contacts];
    }

    input = get_input("FIRST NAME");

    std::cout << "LAST NAME: ";
    std::getline(std::cin, input);

    std::cout << "NICKNAME: ";
    std::getline(std::cin, input);

    std::cout << "PHONE NUMBER: ";
    std::getline(std::cin, input);

    std::cout << "DARKEST SECRET: ";
    std::getline(std::cin, input);
}