#include "Monster.h"

Monster::Monster() : Base() {
    appearance_description = "Unknown";
    cout << "Monster default constructor called" << endl;
}

Monster::Monster(string a, string appearance) : Base(a){
    appearance_description = appearance;
    cout << "Monster parameterized constructor called for: " << a << endl;

}

Monster::Monster(const Monster& other) : Base(other) {
    appearance_description = other.appearance_description;
    cout << "Monster copy constructor called for: " << getName() << endl;
}

Monster::~Monster() {
    cout << "Monster destructor called for: " << getName() << endl;
}

void Monster::print() const {
    cout << "Monster" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Appearance Description: " << appearance_description << endl;
   
}

string Monster::getType() const {
    return "Monster";
}

void Monster::setAppearance(string appearance){
    appearance_description = appearance;

}

string Monster::getAppearance() const{
    return appearance_description;
}