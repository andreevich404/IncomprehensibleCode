#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(int x, int y, int hp)
    : pos_x(x), pos_y(y), hp(hp) {
}

void BaseCharacter::move(int dx, int dy) {
    pos_x += dx;
    pos_y += dy;
}

bool BaseCharacter::is_alive() const {
    return hp > 0;
}

void BaseCharacter::get_damage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}

int BaseCharacter::get_x() const { return pos_x; }
int BaseCharacter::get_y() const { return pos_y; }
int BaseCharacter::get_hp() const { return hp; }
