#include "Villians.h"

Villian::Villian(
    string a,
    string weapon, 
    string evil,
    string lair_location) : Base(a) { 
    
    weapon_type = weapon;
    evilDeed = evil;
    lair = lair_location;  
    skillsCount = 0;      
    
    cout << "Villian parameterized constructor called for: " << a << endl;  // исправил сообщение
}

Villian::Villian(const Villian& other) : Base(other){
    weapon_type= other.weapon_type;
    evilDeed = other.evilDeed;
    lair = other.lair;
    skillsCount = other.skillsCount;

    for(int i = 0; i < skillsCount; i++) {
        mainSkills[i] = other.mainSkills[i];
    }

    cout << "Villian copy constructor called for: " << getName() << endl;
}

Villian::~Villian() {
    cout << "Villian destructor called for: " << getName() << endl;
}

void Villian::print() const {
    cout << "Villian" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Weapon: " << weapon_type << endl;
    cout << "Evil deed: " << evilDeed << endl;
    cout << "Lair: " << lair << endl;
    cout << "Main skills: (" << skillsCount << ")" << endl;
    for(int i = 0; i < skillsCount; i++) {
        cout << "  " << (i+1) << ". " << mainSkills[i] << endl;
    }
    if(skillsCount == 0) {
        cout << "  No skills" << endl;
    }
}

string Villian::getType() const {
    return "Villian";
}

void Villian::setWeaponType(string weapon) {
    weapon_type = weapon;
}

string Villian::getWeaponType() const {
    return weapon_type;
}

void Villian::addSkill(string skill) {
    if(skillsCount < 5) {
        mainSkills[skillsCount] = skill;
        skillsCount++;
    }
}

void Villian::setEvilDeed(string deed){
    evilDeed = deed;
}

string Villian::getEvilDeed() const{
    return evilDeed;
}

void Villian::setLair(string lairLocation){
    lair = lairLocation; 
}

string Villian::getLair() const {
     return lair;
}