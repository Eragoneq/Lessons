#include <iostream>
#include <vector>
#include "random.h"
#include "game_lib.h"

void narysujPlansze(std::vector<char> tablica){
    narysujPlanszex("KOLKO KRZYZYK v0.2", 3, tablica, false);
}

bool checkWinCondition(std::vector<char> tablica){
    for(int i = 0; i<3; i++){
        // X
        if(tablica[i*3] == 'X' && tablica[i*3+1] == 'X' && tablica[i*3+2] == 'X'){
            std::cout << "WYGRANA X";
            return true;
        }
        if(tablica[i] == 'X' && tablica[i+3] == 'X' && tablica[i+6] == 'X'){
            std::cout << "WYGRANA X";
            return true;
        }
        // O
        if(tablica[i*3] == 'O' && tablica[i*3+1] == 'O' && tablica[i*3+2] == 'O'){
            std::cout << "WYGRANA O";
            return true;
        }
        if(tablica[i] == 'O' && tablica[i+3] == 'O' && tablica[i+6] == 'O'){
            std::cout << "WYGRANA O";
            return true;
        }
    }
    // X
    if(tablica[0] == 'X' && tablica[4] == 'X' && tablica[8] == 'X'){
        std::cout << "WYGRANA X";
        return true;
    }
    if(tablica[2] == 'X' && tablica[4] == 'X' && tablica[6] == 'X'){
        std::cout << "WYGRANA X";
        return true;
    }
    // O
    if(tablica[0] == 'O' && tablica[4] == 'O' && tablica[8] == 'O'){
        std::cout << "WYGRANA O";
        return true;
    }
    if(tablica[2] == 'O' && tablica[4] == 'O' && tablica[6] == 'O'){
        std::cout << "WYGRANA O";
        return true;
    }
    return false;
}
void koloKrzyzyk(){
    std::string in;
    std::vector<char> tablica(9);
    bool gameState = true;
    int runda = 0;

    narysujPlansze(tablica);

    while(gameState) {
        std::cout << "Podaj litere i cyfre gdzie chcesz postawic X: (np. A3)\n";
        // PLAYER
        while(true) {
            std::cin >> in;
            int index = in[0] - 'A' + (in[1] - '1') * 3;
            if (in.length() != 2 || (in[0] - 'A') > 2 || (in[1] - '1') > 2 || tablica[index]=='X' || tablica[index]=='O') {
                cls();
                narysujPlansze(tablica);
                std::cout << "Bledne dane\n";
                in.clear();
            } else {
                tablica[index] = 'X';
                cls();
                narysujPlansze(tablica);
                runda++;
                break;
            }
        }
        if(checkWinCondition(tablica)) {
            gameState = false;
            break;
        }
        // AI
        while(runda <= 4) {
            int rand = randInt(0, 8);
            if (tablica[rand] != 'X' && tablica[rand] != 'O') {
                tablica[rand] = 'O';
                cls();
                narysujPlansze(tablica);
                std::cout << rand  << " Runda: " << runda << '\n';
                break;
            }

        }
        if(checkWinCondition(tablica)) {
            gameState = false;
            break;
        }
        //REMIS
        if(runda == 5){
            cls();
            narysujPlansze(tablica);
            std::cout << "REMIS" << '\n';
            gameState = false;
        }
    }
}

void runGierki(){
    koloKrzyzyk();
    std::getchar();
    std::getchar();
}