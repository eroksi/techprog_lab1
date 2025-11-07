#include <iostream>
#include <string>
using namespace std;

class Base{
    private:
        string name;
    public:

    virtual void print() const = 0; 
    virtual string getType() const = 0; 

    virtual ~Base(){
        cout << "Base destructor called for: " << name << endl;
    }

    Base(){
        name = "Unknown";
        cout << "Base default constructor called" << endl;
    }

    Base(string n){
        name = n;
        cout << "Base parameterized constructor called for: " << name << endl;
    }

    Base(const Base& other){
        name = other.name;
        cout << "Base copy constructor called for: " << name << endl;
    }

    string getName() const{
        return name;
    }

    void setName(string new_name){
        name = new_name;
    }
};