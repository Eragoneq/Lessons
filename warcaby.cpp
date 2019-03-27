#include <iostream>
#include <vector>
#include "game_lib.h"

void narysujPlanszeWarcaby(std::vector<char> board){
    narysujPlanszex("Warcaby v0.1", 8, std::move(board), true);
}

std::vector<char> prepareGame(){
    std::vector<char> board;
    board = {' ','b',' ','b',' ','b',' ','b',
           'b',' ','b',' ','b',' ','b',' ',
           ' ','b',' ','b',' ','b',' ','b',
           ' ',' ',' ',' ',' ',' ',' ',' ',
           ' ',' ',' ',' ',' ',' ',' ',' ',
           'c',' ','c',' ','c',' ','c',' ',
           ' ','c',' ','c',' ','c',' ','c',
           'c',' ','c',' ','c',' ','c',' '};
    return board;
}

bool validChoice(std::string place, std::string target, std::vector<char>* boardPtr, int runda){
    int placeIndex, targetIndex;
    std::vector<char> board = *boardPtr;
    // poprawnosc podanych danych
    if(place[0] - 'A' < 8 && target[0] - 'A' < 8 && place[1] - '1' < 8 && target[1] - '1' < 8){
        placeIndex = place[0] - 'A' + (place[1] - '1') * 8;
        targetIndex = target[0] - 'A' + (target[1] - '1') * 8;
    }else return false;
    //sprawdzenie czy istnieje pionek na miejscu
    if((board[placeIndex]=='b' && runda%2==0) || (board[placeIndex]=='c' && runda%2==1)){
        if(targetIndex==(placeIndex-7) || targetIndex==(placeIndex-9) || targetIndex==(placeIndex+7) || targetIndex==(placeIndex+9)){
            if(board[targetIndex] == ' '){
                if(board[placeIndex]=='b'){
                    (*boardPtr)[placeIndex] = ' ';
                    (*boardPtr)[targetIndex] = 'b';
                    return true;
                }else if(board[placeIndex]=='c'){
                    (*boardPtr)[placeIndex] = ' ';
                    (*boardPtr)[targetIndex] = 'c';
                    return true;
                }else return false;
            }else return false;
        }else if(targetIndex==(placeIndex-14) || targetIndex==(placeIndex-18) || targetIndex==(placeIndex+14) || targetIndex==(placeIndex+18)){
            if(((board[(targetIndex+placeIndex)/2]=='c' && runda%2==0) || (board[(targetIndex+placeIndex)/2]=='b' && runda%2==1)) && board[targetIndex] == ' '){
                //wykonano bicie - dodatkowy ruch jeśli możliwe (do dodania)
                if(board[placeIndex]=='b'){
                    (*boardPtr)[placeIndex] = ' ';
                    (*boardPtr)[(targetIndex+placeIndex)/2] = ' ';
                    (*boardPtr)[targetIndex] = 'b';
                    return true;
                }else if(board[placeIndex]=='c'){
                    (*boardPtr)[placeIndex] = ' ';
                    (*boardPtr)[(targetIndex+placeIndex)/2] = ' ';
                    (*boardPtr)[targetIndex] = 'c';
                    return true;
                }else return false;
            }else return false;
        }else return false;
    }else return false;
}

void checkMove(std::vector<char>* board, int* runda){
    std::string place, target;
    while(true) {
        std::cout << "Podaj wspolrzedne pionka a nastepnie jego cel (np. B3 B5):          Runda: " << *runda << " Ruch: " << ((*runda)%2 ? "czarne" : "biale") << std::endl;
        std::cin >> place >> target;
        if(validChoice(place, target, board, *runda)){
            cls();
            narysujPlanszeWarcaby(*board);
            (*runda)++;
            break;
        }else{
            cls();
            narysujPlanszeWarcaby(*board);
            std::cout << "Bledne dane\n";
            place.clear();
            target.clear();
        }
    }

}

void warcaby(){
    bool gameState = true;
    std::vector<char> board = prepareGame();
    int runda = 0;

    narysujPlanszeWarcaby(board);

    while(gameState){
        checkMove(&board, &runda);
    }
}

void runWarcaby(){
    warcaby();
    std::getchar();
    std::getchar();
}