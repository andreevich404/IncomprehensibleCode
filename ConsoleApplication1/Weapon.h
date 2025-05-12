#pragma once
#include <string>
#include <iostream>
#include "BaseCharacter.h"

class Weapon {
private:
    std::string name;
    int damage;
    int range;

public:
    Weapon();
    Weapon(const std::string& name, int damage, int range);

    void hit(BaseCharacter& actor, BaseCharacter& target) const;

    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
    friend std::istream& operator>>(std::istream& is, Weapon& w);

    std::string get_name() const;
    int get_damage() const;
    int get_range() const;
};
