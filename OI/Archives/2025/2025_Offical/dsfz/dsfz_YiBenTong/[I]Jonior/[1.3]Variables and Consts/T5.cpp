#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double r;
    const double PI = 3.14159;
    cin >> r;
    double diameter = 2 * r;
    double circumference = 2 * PI * r;
    double area = PI * r * r;
    cout << fixed << setprecision(4) << diameter << " " << circumference << " " << area << endl;
    return 0;
}