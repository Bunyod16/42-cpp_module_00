#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _total_contacts(0) {}

void    PhoneBook::addContact(int id, char *first_name, char *last_name, char *nickname, char *phone_number, char *darkest_secret) {
    this->contacts[id].AddInfo(first_name, last_name, nickname, phone_number, darkest_secret);
    this->_total_contacts++;
}

void    PhoneBook::search(char *input) {
    char *cmds;
    int x;
    std::cout << "RAN" << std::endl;
    cmds = std::strtok(input, " ");
    for (x = 0; (size_t)x < strlen(cmds); x++) {
        std::cout << cmds[x];
    }
}