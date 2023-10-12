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
