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
    Contact temp(contacts[7]);

    i = 0;
    while (i < 8) {
        contacts[i] = contacts[i + 1];
    }
    contacts[0] = temp;
}

void    PhoneBook::add(void) {
    std::string     info[5];
    info[0] = (char *)get_input("FIRST NAME").c_str();

    info[1] = (char *)get_input("LAST NAME: ").c_str();

    info[2] = (char *)get_input("NICKNAME: ").c_str();

    info[3] = (char *)get_input("PHONE NUMBER: ").c_str();

    info[4] = (char *)get_input("DARKEST SECRET: ").c_str();
    
    Contact         contact(info[0], info[1], info[2], info[3], info[4]);
    if (this->_total_contacts == 8) {
        rotate_array(this->contacts);
        contact = this->contacts[0];
    }
    else {
        contact = this->contacts[_total_contacts];
    }
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
}