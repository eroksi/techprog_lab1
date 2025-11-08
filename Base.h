#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

class Base{
private:
    string name;
public:
    virtual void print() const = 0; 
    virtual string getType() const = 0; 

    virtual ~Base();
    Base();
    Base(string n);
    Base(const Base& other);

    string getName() const;
    void setName(string new_name);
};

#endif