
#ifndef HERO_H
#define HERO_H

#include "Base.h"

class Hero: public Base{
private:
    string weapon_type;
    string mainSkills[5];
    int skillsCount;

public:
    Hero();
    Hero(string hero_name, string weapon);
    Hero(const Hero& other);
    ~Hero();

    void print() const override;
    string getType() const override;

    void setWeaponType(string weapon);
    string getWeaponType() const;
    void addSkill(string skill);

    int getSkillsCount() const;                    
    string getSkill(int index) const;              
    void removeSkill(int index);  
};
#endif
