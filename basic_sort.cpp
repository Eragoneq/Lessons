#include <iostream>
#include <random>
#include <array>
#include <vector>

#define SIZE 100

unsigned long long rdtsc() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return (unsigned long long) hi << 32 | lo;
}

std::mt19937 rng(rdtsc()); // NOLINT(cert-err58-cpp)

int randInt(int min, int max) {
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

std::array<int, SIZE> sort(std::array<int, SIZE> lista) {
    int mini, temp;
    for (int i = 0; i < SIZE; ++i) {
        mini = lista[i];
        for (int j = 0; j < SIZE; ++j) {
            // zamiana elementow
            if (lista[j] >= mini) {
                mini = lista[j];
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }

        }
    }
    return lista;
}

std::vector<int> bubbleSort(std::vector<int> lista) {
    int licznik;
    for(int j = 0; j<lista.size(); j++) {
        licznik = 0;
        for (int i = 0; i < (lista.size()); i++) {
            if (lista[i] > lista[i + 1]) {
                std::swap(lista[i], lista[i + 1]);
            }else{
                licznik++;
            }
        }
        if(licznik==0){
            break;
        }
    }
    return lista;
}

std::vector<int> selectionSort(std::vector<int> lista) {
    int minIndex;
    for(int j = 0; j<lista.size(); j++) {
        minIndex = j;
        for (int i = j; i < (lista.size()); i++) {
            if(lista[i]<lista[minIndex]){
                minIndex = i;
            }
        }
        std::swap(lista[j], lista[minIndex]);
    }
    return lista;
}

std::vector<int> insertSort(std::vector<int> lista) {
    int minIndex;
    int min;
    for(int j = 1; j<lista.size(); j++) {
        minIndex = j;
        min = lista[minIndex];
        int i = 0;
        for(i = j; min>lista[i] && i>0; i--){
            std::swap(lista[i], lista[i-1]);
        }
        lista[i]=min;
    }
    return lista;
}

std::vector<int> bucketSort(std::vector<int> lista) {
    int min = 100;
    int max = 0;
    for(int l : lista){
        if(l<min) min=l;
        if(l>max) max=l;
    }
    std::vector<int> ilosci;
    for(int i = 0; i<=(max-min); i++){
        ilosci.emplace_back(0);
    }
    for(int l : lista){
        ilosci[l-min]++;
    }
    lista.clear();
    for(int i = 0; i<ilosci.size(); i++){
        for(int j = 0; j<ilosci[i]; j++){
            lista.emplace_back(i+min);
        }
    }
    return lista;
}

void runSort() {
    std::array<int, SIZE> array{};
    std::vector<int> vector{};
    for (int i = 0; i < 10; ++i) {
        array[i] = randInt(0, 100);
        vector.emplace_back(randInt(0, 10));
    }
    for (int i : vector) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";
    vector = bucketSort(vector);
    //array = sort(array);

    for (int i : vector) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}





