#include "BaseEnemy.h"

BaseEnemy::BaseEnemy(int x, int y, const Weapon& weapon, int hp)
    : BaseCharacter(x, y, hp), weapon(weapon) {
}

void BaseEnemy::hit(BaseCharacter& target) {
    weapon.hit(*this, target);
}

std::ostream& operator<<(std::ostream& os, const BaseEnemy& enemy) {
    os << "���� �� ������� (" << enemy.pos_x << ", " << enemy.pos_y << ") � ������� " << enemy.weapon;
    return os;
}
