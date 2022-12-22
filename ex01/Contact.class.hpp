#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
using std::string;

class Contact {

 public:
    Contact(string fname, string lname, string nname, string pnum, string dsecret);
    Contact(const Contact &copy);
    ~Contact(void);
    void displayFull(void);
    void displayShort(void);
    void Edit(void);
    ~Contact(void); 
    string getFirstName();
    string getLastName();
    string getNickName();
    string getPhoneNumber();
    string getDarkestSecret();

private:
    string _first_name;
    string _last_name;
    string _nickname;
    string _phone_number;
    string _darkest_secret;

     
    
};


#endif