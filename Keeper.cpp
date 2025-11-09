#include "Keeper.h"

Keeper::Keeper() {
    capacity = 10;
    dataArray = new Base*[capacity];
    size = 0;
    cout << "Keeper default constructor called" << endl;
}

Keeper::Keeper(const Keeper& other) {
    capacity = other.capacity;
    size = other.size;
    dataArray = new Base*[capacity]; 
    
    for(int i = 0; i < size; i++) {
        if(other.dataArray[i]->getType() == "Hero") {
            dataArray[i] = new Hero(*dynamic_cast<Hero*>(other.dataArray[i]));
        } else if(other.dataArray[i]->getType() == "Villian") {
            dataArray[i] = new Villian(*dynamic_cast<Villian*>(other.dataArray[i]));
        } else if(other.dataArray[i]->getType() == "Monster") {
            dataArray[i] = new Monster(*dynamic_cast<Monster*>(other.dataArray[i]));
        }
    }
    cout << "Keeper copy constructor called" << endl;
}

Keeper::~Keeper(){
    for(int i = 0; i < size; i++) {
        delete dataArray[i];
    }
    delete[] dataArray;
    cout << "Keeper destructor called" << endl;
};

void Keeper::resize(){
    int newCapacity = capacity * 2;
    Base** newArray = new Base*[newCapacity];

    for (int i = 0; i < size; i++) {
        newArray[i] = dataArray[i];
    }

    delete[] dataArray;
    dataArray = newArray;
    capacity = newCapacity;
    
    cout << "Keeper resized to capacity: " << capacity << endl;
};

void Keeper::add(Base* obj){
    if (size >= capacity){
        resize();
    }

    dataArray[size] = obj;
    size++;

    cout << "Added" << obj->getType() << ": " << obj->getName() << endl;
};

void Keeper::remove(int index){
    if (index >= size || index < 0){
        cout << "index not valid" << endl;
        return; 
    }

    delete dataArray[index];
    cout << "Removed object at index: " << index << endl;

    for (int i = index; i < size - 1; i++) {
        dataArray[i] = dataArray[i + 1];
    }
    

    size--;
    dataArray[size] = nullptr;

    cout << "Object removed successfully. Total objects: " << size << endl;
};

void Keeper::printALL() const{
    cout << "Keeper Contests" << endl;
    cout << "Total objects: " << size << endl;

    if (size == 0){
        cout << "Keeper is empty(" << endl;
    }


    for (int i = 0; i < size; i++){
        cout << i << ")";
        cout << "Object type: " << dataArray[i]->getType();
        cout << "; Object name: " << dataArray[i]->getName() << endl;
    }
};

void Keeper::saveToFile(const string& filename) const {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }
    
    file << size << endl;

    for (int i = 0; i < size; i++) { 
        file << dataArray[i]->getType() << endl;
        file << dataArray[i]->getName() << endl;
        
        if (dataArray[i]->getType() == "Hero") {
            Hero* hero = dynamic_cast<Hero*>(dataArray[i]);
            file << hero->getWeaponType() << endl;
            file << hero->getSkillsCount() << endl;
            for (int j = 0; j < hero->getSkillsCount(); j++) {
                file << hero->getSkill(j) << endl;
            }
        } else if (dataArray[i]->getType() == "Villian") {
            Villian* villain = dynamic_cast<Villian*>(dataArray[i]);
            file << villain->getWeaponType() << endl;
            file << villain->getEvilDeed() << endl;
            file << villain->getLair() << endl;
            file << villain->getSkillsCount() << endl;        
            for (int j = 0; j < villain->getSkillsCount(); j++) {
                file << villain->getSkill(j) << endl;         
            }
        } else if (dataArray[i]->getType() == "Monster") {
            Monster* monster = dynamic_cast<Monster*>(dataArray[i]);
            file << monster->getAppearance() << endl; 
        }
    }  
    
    file.close();
    cout << "Data saved to " << filename << endl;
}

void Keeper::loadFromFile(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return;
    }
    
    // Очищаем текущие данные
    for (int i = 0; i < size; i++) {
        delete dataArray[i];
    }
    size = 0;
    
    int totalObjects;
    file >> totalObjects;
    file.ignore(); // пропускаем перевод строки
    
    for (int i = 0; i < totalObjects; i++) {
        string type, name;
        getline(file, type);
        getline(file, name);
        
        if (type == "Hero") {
            string weapon;
            int skillCount;
            getline(file, weapon);
            file >> skillCount;
            file.ignore();
            
            Hero* hero = new Hero(name, weapon);
            for (int j = 0; j < skillCount; j++) {
                string skill;
                getline(file, skill);
                hero->addSkill(skill);
            }
            add(hero);
        }
        else if (type == "Villian") {
            string weapon, evilDeed, lair;
            int skillCount;
            getline(file, weapon);
            getline(file, evilDeed);
            getline(file, lair);
            file >> skillCount;
            file.ignore();
            
            Villian* villain = new Villian(name, weapon, evilDeed, lair);
            for (int j = 0; j < skillCount; j++) {
                string skill;
                getline(file, skill);
                villain->addSkill(skill);
            }
            add(villain);
        }
        else if (type == "Monster") {
            string appearance;
            getline(file, appearance);
            Monster* monster = new Monster(name, appearance);
            add(monster);
        }
    }
    
    file.close();
    cout << "Loaded " << totalObjects << " objects from " << filename << endl;
}