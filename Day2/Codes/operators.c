#include <stdio.h>

int main() {
    int num1 = 10, num2 = 5;

    // Arithmetic Operators
    int addition = num1 + num2;         // 10 + 5 = 15
    int subtraction = num1 - num2;      // 10 - 5 = 5
    int multiplication = num1 * num2;   // 10 * 5 = 50
    int division = num1 / num2;         // 10 / 5 = 2
    int modulus = num1 % num2;          // 10 % 5 = 0

    // Relational Operators
    int isEqual = num1 == num2;         // 10 is equal to 5: 0 (False)
    int isNotEqual = num1 != num2;      // 10 is not equal to 5: 1 (True)
    int isGreater = num1 > num2;        // 10 is greater than 5: 1 (True)
    int isLess = num1 < num2;           // 10 is less than 5: 0 (False)
    int isGreaterOrEqual = num1 >= num2; // 10 is greater than or equal to 5: 1 (True)
    int isLessOrEqual = num1 <= num2;    // 10 is less than or equal to 5: 0 (False)

    // Logical Operators
    int logicalAnd = (num1 > 5) && (num1 < 15);   // (10 > 5) && (10 < 15): 1 (True)
    int logicalOr = (num2 > 5) || (num2 > 15);    // (5 > 5) || (5 > 15): 1 (True)
    int logicalNot = !(num1 > num2);             // !(10 > 5): 0 (False)

    // Assignment Operators
    num1 += num2;   // num1 = num1 + num2 => 10 + 5 => 15
    num1 -= num2;   // num1 = num1 - num2 => 15 - 5 => 10
    num1 *= num2;   // num1 = num1 * num2 => 10 * 5 => 50
    num1 /= num2;   // num1 = num1 / num2 => 50 / 5 => 10
    num1 %= num2;   // num1 = num1 % num2 => 10 % 5 => 0

    return 0;
}
