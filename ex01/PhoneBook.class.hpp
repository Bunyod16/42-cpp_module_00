#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"
#include <iostream>

class PhoneBook {
 public:
    PhoneBook(void);
    void search(void);
    void add(void);
    Contact  contacts[3];

 private:
    void    rotate_array(void);
    int      _total_contacts;
};

#endif
