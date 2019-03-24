#include <iostream>
#include <windows.h>
#include "random.h"

void cls( HANDLE hConsole )
{
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    if( !FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
                                     dwConSize, coordScreen, &cCharsWritten ))
        return;
    if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
        return;
    if( !FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
                                     dwConSize, coordScreen, &cCharsWritten ))
        return;
    SetConsoleCursorPosition( hConsole, coordScreen );
}

void narysujPlansze(char tablica[9]){
    std::cout << " KOLKO KRZYZYK v0.1\n";
    std::cout << "     1   2   3   \n";
    std::cout << "   " << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << "\n";
    std::cout << " A " << char(186) << " " << tablica[0] << " " << char(186) << " " << tablica[1] << " " << char(186) << " " << tablica[2] << " " << char(186) << "\n";
    std::cout << "   " << char(204) << char(205) << char(205)  << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << "\n";
    std::cout << " B " << char(186) << " " << tablica[3] << " " << char(186) << " " << tablica[4] << " " << char(186) << " " << tablica[5] << " " << char(186) << "\n";
    std::cout << "   " << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << "\n";
    std::cout << " C " << char(186) << " " << tablica[6] << " " << char(186) << " " << tablica[7] << " " << char(186) << " " << tablica[8] << " " << char(186) << "\n";
    std::cout << "   " << char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << "\n";
}

bool checkWinCondition(const char tablica[]){
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

    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    std::string in;
    char tablica[9] = {};
    bool gameState = true;
    int runda = 0;

    narysujPlansze(tablica);

    while(gameState) {
        std::cout << "Podaj litere i cyfre gdzie chcesz postawic X: (np. A3)\n";
        // PLAYER
        while(true) {
            std::cin >> in;
            int index = in[1] - '1' + (in[0] - 'A') * 3;
            if (in.length() != 2 || (in[0] - 'A') > 2 || (in[1] - '1') > 2 || tablica[index]=='X' || tablica[index]=='O') {
                cls(hStdout);
                narysujPlansze(tablica);
                std::cout << "Bledne dane\n";
                in.clear();
            } else {
                tablica[index] = 'X';
                cls(hStdout);
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
                cls(hStdout);
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
            cls(hStdout);
            narysujPlansze(tablica);
            std::cout << "REMIS" << '\n';
            gameState = false;
        }
    }
}

void runGierki(){
    koloKrzyzyk();
}