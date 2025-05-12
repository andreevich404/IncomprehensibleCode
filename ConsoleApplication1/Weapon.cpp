#include "Weapon.h"
#include <cmath>

Weapon::Weapon() : name("Безымянное"), damage(0), range(0) {}

Weapon::Weapon(const std::string& name, int damage, int range)
    : name(name), damage(damage), range(range) {
}

void Weapon::hit(BaseCharacter& actor, BaseCharacter& target) const {
    if (!target.is_alive()) {
        std::cout << "Враг уже повержен" << std::endl;
        return;
    }

    int dx = actor.get_x() - target.get_x();
    int dy = actor.get_y() - target.get_y();
    double distance = std::sqrt(dx * dx + dy * dy);

    if (distance > range) {
        std::cout << "Враг слишком далеко для оружия " << name << std::endl;
    }
    else {
        std::cout << "Врагу нанесен урон оружием " << name << " в размере " << damage << std::endl;
        target.get_damage(damage);
    }
}

std::ostream& operator<<(std::ostream& os, const Weapon& w) {
    os << w.name;
    return os;
}

std::istream& operator>>(std::istream& is, Weapon& w) {
    std::cout << "Введите имя оружия: ";
    is >> w.name;
    std::cout << "Введите урон: ";
    is >> w.damage;
    std::cout << "Введите радиус: ";
    is >> w.range;
    return is;
}

std::string Weapon::get_name() const { return name; }
int Weapon::get_damage() const { return damage; }
int Weapon::get_range() const { return range; }
