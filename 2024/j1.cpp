#include <iostream>

int main() {

    int r, g, b;

    std::cin >> r;
    std::cin >> g;
    std::cin >> b;

    int cost = r * 3 + g * 4 + b * 5;

    std::cout << cost;

    return 0;
}