#include <iostream>
#include "Contact.class.hpp"

void    Contact::AddInfo(char *ag1, char *ag2, char *ag3, char *ag4, char *ag5) {
    this->first_name = ag1;
    this->last_name = ag2;
    this->nickname = ag3;
    this->phone_number = ag4;
    this->darkest_secret = ag5;
    this->darkest_secret = ag5;
}

Contact::~Contact(void) {
}