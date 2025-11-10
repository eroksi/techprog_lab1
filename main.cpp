#include <iostream>
#include <string>
#include "Keeper.h"
#include "Hero.h"
#include "Villians.h"
#include "Monster.h"

using namespace std;


void showMenu();
void addHero(Keeper& keeper);
void addVillian(Keeper& keeper);
void addMonster(Keeper& keeper);
void removeObject(Keeper& keeper);
void editObject(Keeper& keeper);
void editHero(Hero* hero);
void editVillian(Villian* villian);
void editMonster(Monster* monster);
void saveToFile(Keeper& keeper);
void loadFromFile(Keeper& keeper);
//g++ -o myprogram main.cpp Base.cpp Hero.cpp Villians.cpp Monster.cpp Keeper.cpp
//.\myprogram

int main() {
    Keeper keeper;
    int choice;
    
    cout << "=== HEROES MANAGEMENT SYSTEM ===" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                addHero(keeper);
                break;
            case 2:
                addVillian(keeper);
                break;
            case 3:
                addMonster(keeper);
                break;
            case 4:
                removeObject(keeper);
                break;
            case 5:
                keeper.printALL();
                break;
            case 6:
                editObject(keeper);
                break;
            case 7:
                saveToFile(keeper);
                break;
            case 8:
                loadFromFile(keeper);
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while(choice != 0);
    
    return 0;
}

void showMenu() {
    cout << "\n=== MAIN MENU ===" << endl;
    cout << "1. Add Hero" << endl;
    cout << "2. Add Villain" << endl;
    cout << "3. Add Monster" << endl;
    cout << "4. Remove object" << endl;
    cout << "5. Show all objects" << endl;
    cout << "6. Edit object" << endl;
    cout << "7. Save to file" << endl;
    cout << "8. Load from file" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose option: ";
}

void addHero(Keeper& keeper) {
    string name, weapon;
    cout << "Enter hero name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter weapon: ";
    getline(cin, weapon);
    
    Hero* hero = new Hero(name, weapon);
    
    int skillCount;
    cout << "How many skills? (0-5): ";
    cin >> skillCount;
    cin.ignore();
    
    for (int i = 0; i < skillCount; i++) {
        string skill;
        cout << "Skill " << (i+1) << ": ";
        getline(cin, skill);
        hero->addSkill(skill);
    }
    
    keeper.add(hero);
}

void addVillian(Keeper& keeper) {
    string name, weapon, evilDeed, lair;
    cout << "Enter villain name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter weapon: ";
    getline(cin, weapon);
    cout << "Enter evil deed: ";
    getline(cin, evilDeed);
    cout << "Enter lair: ";
    getline(cin, lair);
    
    Villian* villian = new Villian(name, weapon, evilDeed, lair);
    
    int skillCount;
    cout << "How many skills? (0-5): ";
    cin >> skillCount;
    cin.ignore();
    
    for (int i = 0; i < skillCount; i++) {
        string skill;
        cout << "Skill " << (i+1) << ": ";
        getline(cin, skill);
        villian->addSkill(skill);
    }
    
    keeper.add(villian);
}

void addMonster(Keeper& keeper) {
    string name, appearance;
    cout << "Enter monster name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter appearance description: ";
    getline(cin, appearance);
    
    Monster* monster = new Monster(name, appearance);
    keeper.add(monster);
}

void removeObject(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        cout << "Keeper is empty!" << endl;
        return;
    }
    
    keeper.printALL();
    int index;
    cout << "Enter index to remove: ";
    cin >> index;
    
    keeper.remove(index);
}

void editObject(Keeper& keeper) {
    if (keeper.getSize() == 0) {
        cout << "Keeper is empty!" << endl;
        return;
    }
    
    keeper.printALL();
    int index;
    cout << "Enter index to edit: ";
    cin >> index;
    
    if (index < 0 || index >= keeper.getSize()) {
        cout << "Invalid index!" << endl;
        return;
    }
    
    Base* obj = keeper.getObject(index);
    string type = obj->getType();
    
    if (type == "Hero") {
        editHero(dynamic_cast<Hero*>(obj));
    } else if (type == "Villian") {
        editVillian(dynamic_cast<Villian*>(obj));
    } else if (type == "Monster") {
        editMonster(dynamic_cast<Monster*>(obj));
    }
}

void editHero(Hero* hero) {
    int choice;
    do {
        cout << "\n=== Editing Hero: " << hero->getName() << " ===" << endl;
        cout << "1. Change name" << endl;
        cout << "2. Change weapon" << endl;
        cout << "3. Add skill" << endl;
        cout << "4. Remove skill" << endl;
        cout << "5. Show hero info" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                hero->setName(newName);
                break;
            }
            case 2: {
                string newWeapon;
                cout << "Enter new weapon: ";
                getline(cin, newWeapon);
                hero->setWeaponType(newWeapon);
                break;
            }
            case 3: {
                if (hero->getSkillsCount() >= 5) {
                    cout << "Maximum skills reached (5)!" << endl;
                    break;
                }
                string skill;
                cout << "Enter new skill: ";
                getline(cin, skill);
                hero->addSkill(skill);
                break;
            }
            case 4: {
                if (hero->getSkillsCount() == 0) {
                    cout << "No skills to remove!" << endl;
                    break;
                }
                cout << "Current skills:" << endl;
                for (int i = 0; i < hero->getSkillsCount(); i++) {
                    cout << i << ": " << hero->getSkill(i) << endl;
                }
                int skillIndex;
                cout << "Enter skill index to remove: ";
                cin >> skillIndex;
                hero->removeSkill(skillIndex);
                break;
            }
            case 5:
                hero->print();
                break;
            case 0:
                cout << "Hero editing completed" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while(choice != 0);
}

void editVillian(Villian* villian) {
    int choice;
    do {
        cout << "\n=== Editing Villain: " << villian->getName() << " ===" << endl;
        cout << "1. Change name" << endl;
        cout << "2. Change weapon" << endl;
        cout << "3. Change evil deed" << endl;
        cout << "4. Change lair" << endl;
        cout << "5. Add skill" << endl;
        cout << "6. Remove skill" << endl;
        cout << "7. Show villain info" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                villian->setName(newName);
                break;
            }
            case 2: {
                string newWeapon;
                cout << "Enter new weapon: ";
                getline(cin, newWeapon);
                villian->setWeaponType(newWeapon);
                break;
            }
            case 3: {
                string newEvilDeed;
                cout << "Enter new evil deed: ";
                getline(cin, newEvilDeed);
                villian->setEvilDeed(newEvilDeed);
                break;
            }
            case 4: {
                string newLair;
                cout << "Enter new lair: ";
                getline(cin, newLair);
                villian->setLair(newLair);
                break;
            }
            case 5: {
                if (villian->getSkillsCount() >= 5) {
                    cout << "Maximum skills reached (5)!" << endl;
                    break;
                }
                string skill;
                cout << "Enter new skill: ";
                getline(cin, skill);
                villian->addSkill(skill);
                break;
            }
            case 6: {
                if (villian->getSkillsCount() == 0) {
                    cout << "No skills to remove!" << endl;
                    break;
                }
                cout << "Current skills:" << endl;
                for (int i = 0; i < villian->getSkillsCount(); i++) {
                    cout << i << ": " << villian->getSkill(i) << endl;
                }
                int skillIndex;
                cout << "Enter skill index to remove: ";
                cin >> skillIndex;
                villian->removeSkill(skillIndex);
                break;
            }
            case 7:
                villian->print();
                break;
            case 0:
                cout << "Villain editing completed" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while(choice != 0);
}

void editMonster(Monster* monster) {
    int choice;
    do {
        cout << "\n=== Editing Monster: " << monster->getName() << " ===" << endl;
        cout << "1. Change name" << endl;
        cout << "2. Change appearance description" << endl;
        cout << "3. Show monster info" << endl;
        cout << "0. Back to main menu" << endl;
        cout << "Choose option: ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1: {
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                monster->setName(newName);
                break;
            }
            case 2: {
                string newAppearance;
                cout << "Enter new appearance description: ";
                getline(cin, newAppearance);
                monster->setAppearance(newAppearance);
                break;
            }
            case 3:
                monster->print();
                break;
            case 0:
                cout << "Monster editing completed" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while(choice != 0);
}

void saveToFile(Keeper& keeper) {
    string filename;
    cout << "Enter filename: ";
    cin.ignore();
    getline(cin, filename);
    keeper.saveToFile(filename);
}

void loadFromFile(Keeper& keeper) {
    string filename;
    cout << "Enter filename: ";
    cin.ignore();
    getline(cin, filename);
    keeper.loadFromFile(filename);
}