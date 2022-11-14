#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

public:
    char *first_name;
    char *last_name;
    char *nickname;
    char *phone_number;
    char *darkest_secret;

    void AddInfo(char *first_name, char *last_name, char *nickname, char *phone_number, char *darkest_secret);
    ~Contact(void); 
};


#endif