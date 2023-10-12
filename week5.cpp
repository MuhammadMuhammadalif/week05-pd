// task 2
#include <iostream>
using namespace std;
int l, w, h;

int meter(int l, int w, int h);
int centi(int l, int w, int h);
int kilo(int l, int w, int h);
int milli(int l, int w, int h);
int main()
{

    string unit;
    cout << "Enter the length of the pyramid (in meters): ";
    cin >> l;
    cout << "Enter the width of the pyramid (in meters): ";
    cin >> w;
    cout << "Enter the height of the pyramid (in meters): ";
    cin >> h;
    cout << "Enter the desired output unit (millimeters, centimeters, meters, kilometers): ";
    cin >> unit;
    if (unit == "millimeters")
    {
        cout << "The volume of pyramid is: " << milli(l, w, h) << " cubic millimeters";
    }
    if (unit == "centimeters")
    {
        cout << "The volume of pyramid is: " << centi(l, w, h) << " cubic centimeters";
    }
    if (unit == "meters")
    {
        cout << "The volume of pyramid is: " << meter(l, w, h) << " cubic meters";
    }
    if (unit == "kilometers")
    {
        cout << "The volume of pyramid is: " << kilo(l, w, h) << " cubic kilometers";
    }
    return 0;
}
int milli(int l, int w, int h)
{
    return ((l * w * h) / 3) * 1000;
}
int kilo(int l, int w, int h)
{
    return ((l * w * h) / 3) / 1000;
}
int centi(int l, int w, int h)
{
    return ((l * w * h) / 3) * 100;
}
int meter(int l, int w, int h)
{
    return ((l * w * h) / 3);
}
// task 3
#include <iostream>
using namespace std;
char type;
float price, tax;
float taxCalculator(char type, float price);
main()
{

    cout << "Enter the vehicle type code (M, E, S, V, T): ";
    cin >> type;
    cout << "Enter the price of the vehicle: $";
    cin >> price;
    float f_price = price + taxCalculator(type, price);
    cout << "The finl price of the vehicle of type " << type << " after adding tax is $" << f_price;
}
float taxCalculator(char type, float price)
{
    if (type == 'M')
    {
        tax = price * 0.06;
    }
    if (type == 'E')
    {
        tax = price * (0.08);
    }
    if (type == 'S')
    {
        tax = price * (0.1);
    }
    if (type == 'V')
    {
        tax = price * (0.12);
    }
    if (type == 'T')
    {
        tax = price * (0.14);
    }
    return tax;
}
// task 4
#include <iostream>
using namespace std;
float h, d, w;

float no(float w, float d, float h);
float yes(float w, float d, float h);
main()
{

    cout << "Enter the needed hours: ";
    cin >> h;
    cout << "Enter the days that the firm has: ";
    cin >> d;
    cout << "Enter the number of all workers: ";
    cin >> w;
    float total_h = d * w * 9;
    if (total_h < h)
    {
        cout << "Not enough time! " << yes(w, d, h) << " hours needed.";
    }
    if (total_h > h)
    {
        cout << "Yes! " << no(w, d, h) << " hours left.";
    }
}
float yes(float w, float d, float h)
{
    return h - d * w * 9;
}
float no(float w, float d, float h)

{
    return -(h - d * w * 9);
}
// task 5
#include <iostream>
using namespace std;
void header();
void options();
main()
{
    float f_price;
    header();

    int cloth;

    cout << "1> Add Cloth 1:.." << endl;

    cout << "2> Add Cloth 2:.." << endl;

    cout << "3> Add Cloth 3:.." << endl;

    cout << "4> Add Cloth 4:.." << endl;

    cout << "5> Exit.";
    cout << "_______________________________________________________________________" << endl;
    // here i use while loop by creating my own condition
    while (true)
    {
        cout << "Enter your option:";
        cin >> cloth;
        if (cloth >= 5)
        {
            cout << "#Thanks For Shopping#" << endl;
            break;
        }
        options();
    }
}
void header()
{
    cout << "      -----------------------------------------------------" << endl;
    cout << "      @@@@@@ @     @@@@@ @@@@@     @@@@@ @@@@@ @@@@@ @@@@@ " << endl;
    cout << "      @    @ @       @   @         @   @ @   @   @   @     " << endl;
    cout << "      @@@@@@ @       @   @@@@@     @@@@@ @@@@@   @   @@@@@ " << endl;
    cout << "      @    @ @       @   @         @   @ @@@     @       @ " << endl;
    cout << "      @    @ @@@@@ @@@@@ @         @   @ @  @    @   @@@@@ " << endl;
    cout << "      -----------------------------------------------------" << endl;
}
// it is a functio to display options to user
void options()
{
    string color, size;
    float no, price, discount, discount_price, f_price;

    cout << "Enter the cloth color:.. ";
    cin >> color;

    cout << "Enter the cloth size(Large,Medium,Small):.. ";
    cin >> size;

    cout << "Enter the number of clothes :.. ";
    cin >> no;

    cout << "Enter the cloth price(in PKR):.. ";
    cin >> price;

    cout << "Enter the discount percentage:..";
    cin >> discount;

    discount_price = price * discount / 100;
    f_price = no * (price - discount_price);

    cout << "Final price of " << no << " clothes=" << f_price << endl;
}
// task 6
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