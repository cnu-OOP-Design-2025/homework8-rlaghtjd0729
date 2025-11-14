#include "game.h"

using namespace std;

// --- Concrete Character Implementations ---

// Knight Base Stats: Attack 70, Speed 40, Defense 80
int Knight::getAttack() const { return 70; }
int Knight::getSpeed() const { return 40; }
int Knight::getDefense() const { return 80; }

// Wizard Base Stats: Attack 50, Speed 50, Defense 30
int Wizard::getAttack() const { return 50; }
int Wizard::getSpeed() const { return 50; }
int Wizard::getDefense() const { return 30; }

// Archer Base Stats: Attack 60, Speed 70, Defense 40
int Archer::getAttack() const { return 60; }
int Archer::getSpeed() const { return 70; }
int Archer::getDefense() const { return 40; }

// --- Concrete Decorator Implementations ---

// Armor: Defense +30, Speed -5
string Armor::getDescription() const {
    return character->getDescription() + ", Armor";
}
int Armor::getAttack() const {
    return character->getAttack();
}
int Armor::getSpeed() const {
    return character->getSpeed() - 5;
}
int Armor::getDefense() const {
    return character->getDefense() + 30;
}

// Boots: Speed +15
string Boots::getDescription() const {
    return character->getDescription() + ", Boots";
}
int Boots::getAttack() const {
    return character->getAttack();
}
int Boots::getSpeed() const {
    return character->getSpeed() + 15;
}
int Boots::getDefense() const {
    return character->getDefense();
}

// Staff: Attack +20 (Wizard: +60)
string Staff::getDescription() const {
    return character->getDescription() + ", Staff";
}
int Staff::getAttack() const {
    int attack = character->getAttack() + 20;
    // Wizard Check: Using string matching, which is functional but less robust 
    // than a type check (e.g., dynamic_cast or RTTI) or a dedicated method in a more complex design.
    if (character->getDescription().find("Wizard") != string::npos) {
        // Bonus for Wizard: +40 (Total +60)
        attack += 40; 
    }
    return attack;
}
int Staff::getSpeed() const {
    return character->getSpeed();
}
int Staff::getDefense() const {
    return character->getDefense();
}

// Sword: Attack +30 (Knight: +70)
string Sword::getDescription() const {
    return character->getDescription() + ", Sword";
}
int Sword::getAttack() const {
    int attack = character->getAttack() + 30;
    // Knight Check
    if (character->getDescription().find("Knight") != string::npos) {
        // Bonus for Knight: +40 (Total +70)
        attack += 40;
    }
    return attack;
}
int Sword::getSpeed() const {
    return character->getSpeed();
}
int Sword::getDefense() const {
    return character->getDefense();
}

// Bow: Attack +25 (Archer: +65)
string Bow::getDescription() const {
    return character->getDescription() + ", Bow";
}
int Bow::getAttack() const {
    int attack = character->getAttack() + 25;
    // Archer Check
    if (character->getDescription().find("Archer") != string::npos) {
        // Bonus for Archer: +40 (Total +65)
        attack += 40;
    }
    return attack;
}
int Bow::getSpeed() const {
    return character->getSpeed();
}
int Bow::getDefense() const {
    return character->getDefense();
}