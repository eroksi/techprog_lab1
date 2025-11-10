#ifndef VILLIANS_H
#define VILLIANS_H

#include "Base.h"

class Villian: public Base{
    private:
        string weapon_type;
        string evilDeed;
        string lair;
        string mainSkills[5];
        int skillsCount;
        

    public:
        Villian();
        Villian(
            string name,
            string weapon,
            string evilDeed,
            string lair);
        Villian(const Villian& other);
        ~Villian();

        void print() const override;
        string getType() const override;
        void setWeaponType(string weapon);
        string getWeaponType() const;
        void addSkill(string skill);
        void setEvilDeed(string deed);
        string getEvilDeed() const;
        void setLair(string lairLocation);
        string getLair() const;

        int getSkillsCount() const;
        string getSkill(int index) const; 
        void removeSkill(int index);

};
#endif