#include <iomanip>
#include <iostream>

int main() {
    double F, C;
    std::cin >> F;
    C = 5.0 * (F - 32) / 9.0;
    std::cout << std::fixed << std::setprecision(5) << C << std::endl;
    return 0;
}