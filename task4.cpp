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