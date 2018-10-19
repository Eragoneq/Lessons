#include <iostream>
#include <random>
#include <array>

#define SIZE 100

std::mt19937 rng(static_cast<unsigned int>(__rdtsc()));

int randInt(int min, int max){
    std::uniform_int_distribution<int> uni(min,max);
    return uni(rng);
}

std::array<int, SIZE> sort(std::array<int, SIZE> lista){
    int mini, temp;
    for (int i = 0; i < SIZE; ++i) {
        mini = lista[i];
        for (int j = 0; j < SIZE; ++j) {
            // zamiana elementow
            if (lista[j]>=mini){
                mini = lista[j];
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }

        }
    }


    return lista;
}

void runSort(){
    std::array<int, SIZE> array{};
    for (int i = 0; i < SIZE; ++i) {
        array[i] = randInt(0, 100);
    }

    for (int i = 0; i < SIZE; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n\n";

    array = sort(array);

    for (int i = 0; i < SIZE; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}





