#include "game_lib.h"
#include "warcaby.h"
#include <typeinfo>

void narysujPlanszeWarcaby(board board){
    narysujPlanszex("Warcaby v0.1", 8, board, true);
}

void updateBoard(board* board){
    for(int i = 0; i<board->getElements(); i++){
        auto* ptr = (pionek*)&*board->getPlansza()[i];
        ptr->update();
    }
}

void prepareBoard(board* board1){
    std::vector<char> w;
    w =   {' ','b',' ','b',' ','b',' ','b',
           'b',' ','b',' ','b',' ','b',' ',
           ' ','b',' ','b',' ','b',' ','b',
           ' ',' ',' ',' ',' ',' ',' ',' ',
           ' ',' ',' ',' ',' ',' ',' ',' ',
           'c',' ','c',' ','c',' ','c',' ',
           ' ','c',' ','c',' ','c',' ','c',
           'c',' ','c',' ','c',' ','c',' '};
    board1->setPlansza(w);
    updateBoard(board1);
}

bool validChoice(std::string place, std::string target, board board, int runda){
    int placeIndex, targetIndex;
    // poprawnosc podanych danych
    if(!(board.inPlansza({place[0] - 'A', place[1] - '1'}) && board.inPlansza({target[0] - 'A', target[1] - '1'}))) return false;
    //sprawdzenie czy istnieje pionek na miejscu
//    if((board[placeIndex]=='b' && runda%2==0) || (board[placeIndex]=='c' && runda%2==1)){
//        if(targetIndex==(placeIndex-7) || targetIndex==(placeIndex-9) || targetIndex==(placeIndex+7) || targetIndex==(placeIndex+9)){
//            if(board[targetIndex] == ' '){
//                if(board[placeIndex]=='b'){
//                    (*boardPtr)[placeIndex] = ' ';
//                    (*boardPtr)[targetIndex] = 'b';
//                    return true;
//                }else if(board[placeIndex]=='c'){
//                    (*boardPtr)[placeIndex] = ' ';
//                    (*boardPtr)[targetIndex] = 'c';
//                    return true;
//                }else return false;
//            }else return false;
//        }else if(targetIndex==(placeIndex-14) || targetIndex==(placeIndex-18) || targetIndex==(placeIndex+14) || targetIndex==(placeIndex+18)){
//            if(((board[(targetIndex+placeIndex)/2]=='c' && runda%2==0) || (board[(targetIndex+placeIndex)/2]=='b' && runda%2==1)) && board[targetIndex] == ' '){
//                //wykonano bicie - dodatkowy ruch jeśli możliwe (do dodania)
//                if(board[placeIndex]=='b'){
//                    (*boardPtr)[placeIndex] = ' ';
//                    (*boardPtr)[(targetIndex+placeIndex)/2] = ' ';
//                    (*boardPtr)[targetIndex] = 'b';
//                    return true;
//                }else if(board[placeIndex]=='c'){
//                    (*boardPtr)[placeIndex] = ' ';
//                    (*boardPtr)[(targetIndex+placeIndex)/2] = ' ';
//                    (*boardPtr)[targetIndex] = 'c';
//                    return true;
//                }else return false;
//            }else return false;
//        }else return false;
//    }else return false;
}

//void checkMove(board board, int* runda){
//    std::string place, target;
//    while(true) {
//        std::cout << "Podaj wspolrzedne pionka a nastepnie jego cel (np. B3 B5):          Runda: " << *runda << " Ruch: " << ((*runda)%2 ? "czarne" : "biale") << std::endl;
//        std::cin >> place >> target;
//        if(validChoice(place, target, board, *runda)){
//            cls();
//            narysujPlanszeWarcaby(*board);
//            (*runda)++;
//            break;
//        }else{
//            cls();
//            narysujPlanszeWarcaby(*board);
//            std::cout << "Bledne dane\n";
//            place.clear();
//            target.clear();
//        }
//    }
//}

void warcaby(){

    bool gameState = true;
    board board(8);
    prepareBoard(&board);
    int runda = 0;
    for(int i = 0; i<board.getElements(); i++){
        auto* ptr = (pionek*)&*board.getPlansza()[i];
        std::cout << ptr->getColor() << " " << ptr->getType() << "\n";
    }

    //narysujPlanszeWarcaby(board);

//    while(gameState){
//        checkMove(&board, &runda);
//    }
}

void runWarcaby(){
    warcaby();
    std::getchar();
    std::getchar();
}