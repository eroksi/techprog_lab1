#include "Hero.h"

Hero::Hero(): Base(){
    weapon_type = "No";
    skillsCount = 0;
    cout << "Hero default constructor called for unknown hero"<< endl;
}

Hero::Hero(string a, string weapon) : Base(a) {
    weapon_type = weapon;
    skillsCount = 0;
    cout << "Hero parameterized constructor called for: " << a << endl;
}

Hero::Hero(const Hero& other) : Base(other) {
    weapon_type = other.weapon_type;
    skillsCount = other.skillsCount;
    for(int i = 0; i < skillsCount; i++) {
        mainSkills[i] = other.mainSkills[i];
    }
    cout << "Hero copy constructor called for: " << getName() << endl;
}

Hero::~Hero() {
    cout << "Hero destructor called for: " << getName() << endl;
}

void Hero::print() const {
    cout << "Positive Hero" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Weapon: " << weapon_type << endl;
    cout << "Main skills: (" << skillsCount << ")" << endl;
    for(int i = 0; i < skillsCount; i++) {
        cout << "  " << (i+1) << ". " << mainSkills[i] << endl;
    }
    if(skillsCount == 0) {
        cout << "  No skills" << endl;
    }
}

string Hero::getType() const {
    return "Hero";
}

void Hero::setWeaponType(string weapon) {
    weapon_type = weapon;
}

string Hero::getWeaponType() const {
    return weapon_type;
}

void Hero::addSkill(string skill) {
    if(skillsCount < 5) {
        mainSkills[skillsCount] = skill;
        skillsCount++;
    }
}