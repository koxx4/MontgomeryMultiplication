#include <iostream>
#include <cmath>

int normalNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int transformedNumbers[10];

int transformIntoMontgomerySpace(int number, int r, int n) {

    return (number * r) % n;
}


int main() {

    printf("Untransformed numbers:\n");

    for(int n : normalNumbers) {
        printf(" |%d| ", n);
    }

    std::cout << std::endl;

    for(int i = 0; i < 10; i++) {
        transformedNumbers[i] = transformIntoMontgomerySpace(normalNumbers[i], 64, 65);
    }

    printf("Transformed numbers into montgomery space:\n");

    for(int n : transformedNumbers) {
        printf(" |%d| ", n);
    }

    std::cout << std::endl;

    return 0;
}