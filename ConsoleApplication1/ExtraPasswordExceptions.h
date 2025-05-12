#pragma once
#include <stdexcept>

class ExtraPasswordError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class SpaceError : public ExtraPasswordError {
public:
    SpaceError() : ExtraPasswordError("Пароль не должен содержать пробелов") {}
};

class RepeatCharError : public ExtraPasswordError {
public:
    RepeatCharError() : ExtraPasswordError("Пароль не должен содержать подряд более 3 одинаковых символов") {}
};
