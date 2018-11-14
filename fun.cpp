#include <iostream>

void fun(){
    char znak;
    std::cout << "Podaj znak\n";
    std::cin >> znak;
    if(znak!='.'){
        fun();
        std::cout << znak;
    }
}

void runFun(){
    fun();
}