#ifndef PROJEKCIK_GAME_LIB_H
#define PROJEKCIK_GAME_LIB_H

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void cls()
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

void narysujPlanszex(std::string name, int size, std::vector<char> tablica, bool isCheckered) {
    std::string spacing = (size>=10 ? "    " : "   ");
    std::cout << spacing << name << std::endl;
    // Oznaczenia gora
    std::cout << spacing << " ";
    for (int i = 0; i < size; i++) std::cout << " " << char('A' + i) << "  ";
    std::cout << std::endl;
    // gorny bok
    std::cout << spacing << char(201) << char(205) << char(205) << char(205);
    for (int i = 0; i < (size - 1); i++) std::cout << char(203) << char(205) << char(205) << char(205);
    std::cout << char(187) << std::endl;
    // środki
    for (int i = 0; i < (size - 1); i++) {
        std::cout << " " << i + 1 << ((i + 1) < 10 && size >=10 ? "  " : " ");
        for (int j = 0; j < size; j++) {
            std::cout << char(186);
            (i+j)%2==0 && isCheckered ? SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) : SetConsoleTextAttribute(hConsole, 15);
            std::cout << " " << tablica[size * i + j] << " ";
            (i+j)%2==0 ? SetConsoleTextAttribute(hConsole, 15) : false;
        }
        std::cout << char(186) << std::endl;
        //
        std::cout << spacing << char(204) << char(205) << char(205) << char(205);
        for (int j = 0; j < (size - 1); j++) std::cout << char(206) << char(205) << char(205) << char(205);
        std::cout << char(185) << std::endl;
    }
    //dolny koniec |__
    std::cout << " " << size << " ";
    for (int j = 0; j < size; j++) {
        std::cout << char(186);
        ((size - 1)+j)%2==0 && isCheckered ? SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED) : SetConsoleTextAttribute(hConsole, 15);
        std::cout << " " << tablica[size * (size - 1) + j] << " ";
        ((size - 1)+j)%2==0 ? SetConsoleTextAttribute(hConsole, 15) : false;
    }
    std::cout << char(186) << std::endl;
    std::cout << spacing << char(200) << char(205) << char(205) << char(205);
    for (int i = 0; i < (size - 1); i++) std::cout << char(202) << char(205) << char(205) << char(205);
    std::cout << char(188) << std::endl;
}

#endif //PROJEKCIK_GAME_LIB_H
