#pragma once

class BaseCharacter {
protected:
    int pos_x, pos_y;
    int hp;

public:
    BaseCharacter(int x, int y, int hp);

    void move(int dx, int dy);
    bool is_alive() const;
    void get_damage(int amount);
    int get_x() const;
    int get_y() const;
    int get_hp() const;
};
