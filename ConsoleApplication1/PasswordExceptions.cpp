#include "PasswordExceptions.h"

LengthError::LengthError(): PasswordError("������ ������ ���� �� ������ 9 ��������") {}

RegisterError::RegisterError(): PasswordError("������ ������ ��������� ������� ������ ���������") {}

DigitError::DigitError(): PasswordError("������ ������ ��������� ���� �� ���� �����") {}

ForbiddenLetterError::ForbiddenLetterError(): PasswordError("������ �������� ����������� ������� (l, I, 1, o, O, 0)") {}