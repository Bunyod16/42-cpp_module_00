#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include "Contact.class.hpp"

class PhoneBook {
 public:
    PhoneBook(void);
    void addContact(int id, char *first_name, char *last_name, char *nickname, char *phone_number, char *darkest_secret);
    void search(char *input);

 private:
   Contact  contacts[8];
   int      _total_contacts;
};

#endif
