#include <iostream>
#include <string>
#include "./PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
    this->_total_contacts = 0;
}

void PhoneBook::rotate_array(void) {
    int i;
    Contact temp(contacts[7]);

    i = 0;
    while (i < 8) {
        contacts[i] = contacts[i + 1];
    }
    contacts[this->_total_contacts - 1] = save;
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

void    PhoneBook::search(void) {
    display_all_contacts(this->contacts, this->_total_contacts);
}
