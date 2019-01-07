#include <iostream>

void runBitTest() {
    float suma1, suma2 = 0;
    for (int i = 1; i <= 100000000; i++) {
        suma1 += (1.0 / i);
    }
    for (int i = 100000000; i >= 1; i--) {
        suma2 += (1.0 / i);
    }
}