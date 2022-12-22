#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"
#include <iostream>

class PhoneBook {
 public:
    PhoneBook(void);
    void addContact(int id, char *first_name, char *last_name, char *nickname, char *phone_number, char *darkest_secret);
    void search(void);
    void add(void);
    Contact  contacts[8];

 private:
    void    rotate_array(void);
    int      _total_contacts;
};

#endif
