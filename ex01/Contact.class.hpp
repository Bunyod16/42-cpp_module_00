#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

 public:
    void displayFull(void);
    void displayShort(void);
    void Edit(void);
    ~Contact(void); 
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};


#endif