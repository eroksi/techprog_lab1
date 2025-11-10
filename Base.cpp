#include "Base.h"

Base::~Base(){
    cout << "Base destructor called for: " << name << endl;
}

Base::Base(){
    name = "Unknown";
    cout << "Base default constructor called" << endl;
}

Base::Base(string n){
    name = n;
    cout << "Base parameterized constructor called for: " << name << endl;
}

Base::Base(const Base& other){
    name = other.name;
    cout << "Base copy constructor called for: " << name << endl;
}

string Base::getName() const{
    return name;
}

void Base::setName(string new_name){
    name = new_name;
}