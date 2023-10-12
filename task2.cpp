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
    return ((l * w * h)/3) * 1000;
}
int kilo(int l, int w, int h)
{
    return ((l * w * h)/3) / 1000;
}
int centi(int l, int w, int h)
{
    return ((l * w * h)/3) * 100;
}
int meter(int l, int w, int h)
{
    return ((l * w * h)/3);
}
