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

void    PhoneBook::add(void) {
    std::string     input;
    Contact         contact;

    if (this->_total_contacts == 8) {
        rotate_array(this->contacts);
        contact = this->contacts[0];
    }
    else {
        contact = this->contacts[_total_contacts];
    }
    contact.first_name = (char *)get_input("FIRST NAME").c_str();

    contact.last_name = (char *)get_input("LAST NAME: ").c_str();

    contact.nickname = (char *)get_input("NICKNAME: ").c_str();

    contact.phone_number = (char *)get_input("PHONE NUMBER: ").c_str();

    contact.darkest_secret = (char *)get_input("DARKEST SECRET: ").c_str();
    this->_total_contacts++;
}

std::string add_padding(int width, const std::string& str) {
    int len = str.length();
    if(width < len) { return str; }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return std::string(pad1, ' ') + str + std::string(pad2, ' ');
}

void    display_all_contacts(Contact *contacts, int total_contacts) {
    int i;

    i = -1;
    while (++i < total_contacts) {
        std::cout << add_padding(3, std::to_string(i)) << "|";
        std::cout << add_padding(3, std::()) << "|";
    }
}

void    PhoneBook::search(void) {
    display_all_contacts(this->contacts, this->_total_contacts);
    // display_single_contact();
}