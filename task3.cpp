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