#include <iostream>
#include <string>
#include "./PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
    this->_total_contacts = 0;
}

void PhoneBook::rotate_array(void) {
    int i;
    Contact save;

    i = 0;
    save = contacts[0];
    while (i < this->_total_contacts - 1) {
        this->contacts[i] = this->contacts[i + 1];
        i++;
    }
    contacts[this->_total_contacts - 1] = save;
}

void    PhoneBook::add(void) {
    if (_total_contacts == 8) {
        this->contacts[0].Edit();
        rotate_array();
        this->_total_contacts = this->_total_contacts - 1;
    } else {
        this->contacts[this->_total_contacts].Edit();
    }
    this->_total_contacts++;
}

void    PhoneBook::search(void) {
    int i;
    int id;
    std::string input;

    if (this->_total_contacts == 0){
        std::cout << "Error: no contacts to show" << std::endl;
        return;
    }
    std::cout << "+---+----------+----------+----------+" << std::endl;
    std::cout << "| ID|FIRST NAME| LAST NAME| NICK NAME|" << std::endl;
    std::cout << "+---+----------+----------+----------+" << std::endl;

    i = -1;
    while (++i < this->_total_contacts) {
        std::cout << "|  " << std::to_string(i) << "|";
        this->contacts[i].displayShort();
    }
    std::cout << "|---|----------|----------|----------|" << std::endl;
    std::cout << "SELECT ID: ";
    std::getline(std::cin, input);

    i = -1;
    while (input[++i]) {
        if (!isdigit(input[i]) && !(i == 0 && input[i] == '-')) {
            std::cout << "Error: not a number" << std::endl;
            return;
        }
    }
    id = std::stoi(input);
    if (id > this->_total_contacts  - 1 || id < 0) {
        std::cout << "Error: index out of range" << std::endl;
        return;
    }
    this->contacts[id].displayFull();
}
