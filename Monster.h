#ifndef MONSTER_H
#define MONSTER_H

#include "Base.h"

class Monster: public Base{
    private:
        string appearance_description;
        

    public:
    Monster();
    Monster(string a, string appearance);
    Monster(const Monster& other);
    ~Monster();

    void print() const override;
    string getType() const override;

    void setAppearance(string appearance);
    string getAppearance() const;
};
#endif