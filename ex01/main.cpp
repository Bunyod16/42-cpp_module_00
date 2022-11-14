#include <iostream>
#include "PhoneBook.class.hpp"

int main(void) {
    char        input[256];
    PhoneBook   phonebook;

    while (std::strcmp(input, "EXIT")) {
        std::cout << "COMMAND: ";
        std::cin >> input;

        if (!std::strcmp(input, "SEARCH")) {
            phonebook.search(input);
        }
    }
}