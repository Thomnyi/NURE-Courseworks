#include <iostream>

int euclideanGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclideanGCD(b, a % b);
}

int main()
{
    int a, b, GCD;
    std::cout << "Please enter two positive numbers: ";
    std::cin >> a;
    std::cin >> b;
    while (a < 0) {
        std::cout << std::endl << "Numbers cannot be negative. Please, enter another 'a': ";
        std::cin >> a;
    }
    while (b < 0) {
        std::cout << std::endl << "Numbers cannot be negative. Please, enter another 'b': ";
        std::cin >> b;
    }
    GCD = euclideanGCD(a, b);
    std::cout << "The greatest common divisor of the two numbers is " << GCD;
    return 0;
}