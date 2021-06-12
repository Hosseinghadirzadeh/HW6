//
// Created by Hossein on 6/12/2021.
//

#include "Address.h"

Address::Address() {
     country="";
     city="";
     street="";

}


const string &Address::getCountry() const {
    return country;
}

void Address::setCountry(const string &country) {
    Address::country = country;
}

const string &Address::getCity() const {
    return city;
}

void Address::setCity(const string &city) {
    Address::city = city;
}

const string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

Address::Address(string country , string city, string street) {
  setCountry(country);
  setCity(city);
  setStreet(street);
}

ostream &operator<<(ostream & out, const Address & a) {
    out<<"Country: "<<a.getCountry()<<endl<<" City: "<<a.getCity()<<endl<<" street: "<<a.getStreet()<<endl;
    return out;
}

istream &operator>>(istream & in, Address & a) {
    cout<<"COUNTRY-CITY-STREET:\n";
    in>>a.country>>a.city>>a.street;
    return in;
}
