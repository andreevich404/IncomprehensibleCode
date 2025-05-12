#include "Password.h"
#include <iostream>
#include <cctype>
#include <set>
#include "ExtraPasswordExceptions.h"

std::string get_password() {
    std::string password;
    std::cout << "¬ведите пароль: ";
    std::cin >> password;

    if (password.length() < 9) throw LengthError();

    bool has_upper = false, has_lower = false, has_digit = false;
    std::set<char> forbidden = { 'l', 'I', '1', 'o', 'O', '0' };

    for (char ch : password) {
        if (std::isdigit(ch)) has_digit = true;
        if (std::islower(ch)) has_lower = true;
        if (std::isupper(ch)) has_upper = true;
        if (forbidden.count(ch)) throw ForbiddenLetterError();
    }

    if (password.find(' ') != std::string::npos) {
        throw SpaceError();
    }

    int repeat_count = 1;
    for (size_t i = 1; i < password.length(); ++i) {
        if (password[i] == password[i - 1]) {
            repeat_count++;
            if (repeat_count > 3) throw RepeatCharError();
        }
        else {
            repeat_count = 1;
        }
    }

    if (!has_digit) throw DigitError();
    if (!(has_upper && has_lower)) throw RegisterError();

    return password;
}