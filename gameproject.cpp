#include <iostream>
#include <windows.h>
using namespace std;
void boundry();
void gotoxy(int x, int y);
char getCharAtXY(short int x, short int y);
void player();
void enemy1();
// void enemy2();
void eraseenemy1();
void moveenemy1();
// void eraseenemy2();
// void moveenemy2();
void eraseplayer();
void moveplayerleft();
void moveplayerright();
int pX = 25, pY = 17;
int eX = 14, eY = 6;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

main()
{
    boundry();
    enemy1();
    // enemy2();
    player();
    eraseplayer();
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveplayerright();
        }

        moveenemy1();
        Sleep(300);
    }
}
char getCharAtXY(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void boundry()
{
    SetConsoleTextAttribute(h, 1);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@|--------------------------------------------------------|@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|             -----------------------------              |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|-------------                             --------------|@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|                                                        |@" << endl;
    cout << "@|--------------------------------------------------------|@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
}
void player()
{
    SetConsoleTextAttribute(h, 10);
    gotoxy(pX, pY);
    cout << " /---\\" << endl;
    gotoxy(pX, pY + 1);
    cout << " \\---/" << endl;
    gotoxy(pX, pY + 2);
    cout << " _|^|_" << endl;
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    return;
}
void enemy1()
{
    SetConsoleTextAttribute(h, 4);
    gotoxy(eX, eY);
    cout << " (_)" << endl;

    gotoxy(eX, eY + 1);
    cout << "/---\\" << endl;

    gotoxy(eX, eY + 2);
    cout << "|'''|"
         << endl;
}

// void enemy2()
// {
//     gotoxy(eX + 45, eY + 6);
//     cout << "||__||" << endl;
//     gotoxy(eX + 45, eY + 7);
//     cout << "\\----/" << endl;
//     gotoxy(eX + 45, eY + 8);
//     cout << "  ( )" << endl;
// }

void eraseenemy1()
{
    gotoxy(eX, eY);
    cout << "      ";
    gotoxy(eX, eY + 1);
    cout << "      ";
    gotoxy(eX, eY + 2);
    cout << "      ";
}
void moveenemy1()
{
    eraseenemy1();
    eX = eX + 1;
    if (eX == 40)
    {
        eX = 14;
    }
    enemy1();
}
// void eraseenemy2()
// {
//     gotoxy(eX + 45, eY + 6);
//     cout << "      ";
//     gotoxy(eX + 45, eY + 7);
//     cout << "      ";
//     gotoxy(eX + 45, eY + 8);
//     cout << "      ";
// }
// void moveenemy2()
// {
//     eraseenemy2();
//     eX = eX + 45;
//     if (eX == 25)
//     {
//         eX = 45;
//     }
//     enemy2();
// }
void moveplayerleft()
{
    eraseplayer();
    if (pX == 4)
    {
        pX = pX + 1;
    }
    pX = pX - 1;
    player();
}
void moveplayerright()
{
    eraseplayer();
    if (pX == 50)
    {
        pX = pX - 1;
    }
    pX = pX + 1;
    player();
}
void eraseplayer()
{
    gotoxy(pX, pY);
    cout << "      ";
    gotoxy(pX, pY + 1);
    cout << "      ";
    gotoxy(pX, pY + 2);
    cout << "      ";
}