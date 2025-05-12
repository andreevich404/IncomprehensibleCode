#include "MainHero.h"
#include "GameExceptions.h"
#include <iostream>

MainHero::MainHero(int x, int y, const std::string& name, int hp)
    : BaseCharacter(x, y, hp), name(name), current_weapon_index(-1) {
}

void MainHero::hit(BaseCharacter& target) {
    if (inventory.empty()) {
        throw NoWeaponError();
    }
    inventory[current_weapon_index].hit(*this, target);
}


void MainHero::add_weapon(const Weapon& weapon) {
    inventory.push_back(weapon);
    std::cout << "�������� " << weapon << std::endl;
    if (inventory.size() == 1) {
        current_weapon_index = 0;
    }
}

void MainHero::next_weapon() {
    if (inventory.empty()) {
        std::cout << "� ���������" << std::endl;
    }
    else if (inventory.size() == 1) {
        std::cout << "� ���� ������ ���� ������" << std::endl;
    }
    else {
        current_weapon_index = (current_weapon_index + 1) % inventory.size();
        std::cout << "������ ������ �� " << inventory[current_weapon_index] << std::endl;
    }
}

void MainHero::heal(int amount) {
    hp += amount;
    if (hp > 200) {
        throw OverhealError();
    }
    std::cout << "���������, ������ �������� " << hp << std::endl;
}
