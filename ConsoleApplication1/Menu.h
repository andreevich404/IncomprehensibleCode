#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <functional>

class Menu {
public:
    void initialize(); // Инициализация всех заданий
    void addItem(const std::string& name, std::function<void()> action);
    void run();

private:
    struct MenuItem {
        std::string name;
        std::function<void()> action;
    };

    std::vector<MenuItem> items;

    // Функции заданий
    void task1();
    void task2();
    void task3();
    void task4();
    void task1_circle();
    void task1_rectangle();
    void task2_early_binding();
    void task2_late_binding();
};

#endif // MENU_H