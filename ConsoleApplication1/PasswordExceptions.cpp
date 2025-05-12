#include "PasswordExceptions.h"

LengthError::LengthError(): PasswordError("Пароль должен быть не короче 9 символов") {}

RegisterError::RegisterError(): PasswordError("Пароль должен содержать символы разных регистров") {}

DigitError::DigitError(): PasswordError("Пароль должен содержать хотя бы одну цифру") {}

ForbiddenLetterError::ForbiddenLetterError(): PasswordError("Пароль содержит запрещенные символы (l, I, 1, o, O, 0)") {}