#pragma once
#include "stdafx.h"

class LabMenu {
public:
    void run();

private:
    void clearInput();
    template <typename T> T getInput(const std::string& prompt);
    void showMainMenu();
    void clearScreen();
};