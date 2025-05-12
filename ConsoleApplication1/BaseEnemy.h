#pragma once
#include "BaseCharacter.h"
#include "Weapon.h"
#include <iostream>

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    BaseEnemy(int x, int y, const Weapon& weapon, int hp);

    void hit(BaseCharacter& target);
    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy);
};
