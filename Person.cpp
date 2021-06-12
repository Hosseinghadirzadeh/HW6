//
// Created by Hossein on 6/13/2021.
//

#include "Person.h"
#include <cstring>

#include <utility>

Person::Person() {
    name = "";
    id = "";
    address.setCountry("");
    address.setStreet("");
    address.setCity("");
}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    this->name = name;
}

const string &Person::getId() const {
    return id;
}

void Person::setId(const string &id) {
    this->id = id;
}

const Address &Person::getAddress() const {
    return address;
}

void Person::setAddress(const Address &address) {
    this->address = address;
}

Person::Person(string name, string id, Address address) : name(std::move(name)), id(std::move(id)),
                                                          address(std::move(address)) {

    if(!validate())
    {cout<<"invalid id";
        return;
    }

}

Person::Person(const Person &p) {
    name = p.name;
    id = p.id;
    address = p.address;
}

bool Person::validate() {//we have separate id into three group of 8,9,10 char length
    if (id.length()<8||id.length()>10)
        return false;
    string sal = id.substr(0, 2);

    if (stoi(sal) < 84 || stoi(sal) > 99)
        return false;

    if (id.length() == 8) {
        for (int i = 0; i <= 9; ++i) {
            if (id[2]-48 == i)
                return false;
        }
        for (int i = 3; i < 8; ++i) {
            if (id[i]-48==4||id[i]-48==5||id[i]-48==6)
                return false;
        }
    }
    if (id.length() == 9) {
        for (int j = 2; j <= 3; ++j) {
            for (int i = 0; i <= 9; ++i) {
                if (id[j]-48 == i)
                    return false;
            }
        } for (int i = 4; i < 8; ++i) {
            if (id[i]-48==4||id[i]-48==5||id[i]-48==6)
                return false;
        }
    }
    if (id.length() == 10) {
        for (int j = 2; j <= 4; ++j) {
            for (int i = 0; i <= 9; ++i) {
                if (id[j] -48== i)
                    return false;
            }
        } for (int i = 5; i < 8; ++i) {
            if (id[i]-48==4||id[i]-48==5||id[i]-48==6)
                return false;
        }
    }
    return true;

}

Person &Person::operator=(const Person &p) {
    name = p.name;
    id = p.id;
    address = p.address;
    return *this;
}

ostream &operator<<(ostream &out, const Person &p) {
    out << " Name: " << p.name << endl << " ID: " << p.id << endl << " address:\n " << p.address << endl;
    return out;
}

istream &operator>>(istream &in, Person &p) {
    cout << "NAME - ID - ADDRESS:\n";
    in >> p.name >> p.id >> p.address;
    return in;
}
