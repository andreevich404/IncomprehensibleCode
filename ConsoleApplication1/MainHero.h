#pragma once
#include "BaseCharacter.h"
#include "Weapon.h"
#include <vector>
#include <string>

class MainHero : public BaseCharacter {
private:
    std::string name;
    std::vector<Weapon> inventory;
    int current_weapon_index;

public:
    MainHero(int x, int y, const std::string& name, int hp);

    void hit(BaseCharacter& target);
    void add_weapon(const Weapon& weapon);
    void next_weapon();
    void heal(int amount);
};
