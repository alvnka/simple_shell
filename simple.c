#include <stdio.h>

// Function to calculate the factorial of a positive integer
unsigned int factorial(unsigned int m) {
    if (m == 0 || m == 1) {
        return 1;
    }

    unsigned int result = 1;
    for (unsigned int i = 2; i <= m; i++) {
        result *= i;
    }

    return result;
}

int main() {
    unsigned int number = 5;
    unsigned int result = factorial(number);

    printf("Factorial of %u is %u\m", number, result);
    return 0;
}

