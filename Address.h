//
// Created by Hossein on 6/12/2021.
//
#include <iostream>

#ifndef HW6_ADDRESS_H
#define HW6_ADDRESS_H
using namespace std;

class Address {
private:
    string country;
    string city;
    string street;
public:
    Address();

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getCity() const;

    void setCity(const string &city);

    const string &getStreet() const;

    void setStreet(const string &street);

    Address(string, string, string);

    friend ostream &operator<<(ostream &, const Address &);

    friend istream &operator>>(istream &, Address &);
};


#endif //HW6_ADDRESS_H
