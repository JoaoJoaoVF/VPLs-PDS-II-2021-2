#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a = 0;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    double dx = x1 - x2;
    double dy = y1 - y2;
    a = sqrt(dx * dx + dy * dy);
    cout << a << endl;
}