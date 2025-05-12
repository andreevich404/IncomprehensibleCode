#pragma once
#include <stdexcept>

class PasswordError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class LengthError : public PasswordError {
public:
    LengthError();
};

class RegisterError : public PasswordError {
public:
    RegisterError();
};

class DigitError : public PasswordError {
public:
    DigitError();
};

class ForbiddenLetterError : public PasswordError {
public:
    ForbiddenLetterError();
};
