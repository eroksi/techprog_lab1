#include "Base.h"
#include "Hero.h"
#include "Villians.h"
#include "Monster.h"
#include <fstream>
#include <string>

using namespace std;

class Keeper{
    private:
        Base** dataArray;
        int size;
        int capacity;


    public:

        Keeper();
        Keeper(const Keeper& other);
        ~Keeper();


        void resize();
        void remove(int index);
        void add(Base* obj);
        void printALL() const;
        void saveToFile(const string& filename) const;
        void loadFromFile(const string& filename);
        int getSize() const;

        Base* getObject(int index) const;
};