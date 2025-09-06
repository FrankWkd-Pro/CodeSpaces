#include <iomanip>
#include <iostream>

int main() {
    double r1, r2;
    std::cin >> r1 >> r2;

    double ans = 1 / (1 / r1 + 1 / r2);

    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;

    return 0;
}