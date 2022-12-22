#include <iostream>
#include "Contact.class.hpp"

using std::string;

Contact::Contact(string fname, string lname, string nname, string pnum, string dsecret) : _first_name(fname), _last_name(lname), _nickname(nname), _phone_number(pnum), _darkest_secret(dsecret) {}

Contact::Contact(const Contact &copy) {
    _first_name = copy._first_name;
    _last_name = copy._last_name;
    _nickname = copy._nickname;
    _phone_number = copy._phone_number;
    _darkest_secret = copy._darkest_secret;
}

Contact::~Contact(void) {
}

string Contact::getFirstName()
{
    return (_first_name);
}

string Contact::getLastName()
{
    return (_last_name);
}

string Contact::getNickName()
{
    return (_nickname);
}

string Contact::getPhoneNumber()
{
    return (_phone_number);
}

string Contact::getDarkestSecret()
{
    return (_darkest_secret);
}
