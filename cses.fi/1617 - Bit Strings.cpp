#include <iostream>
int main() {
    int n, r = 1;
    std::cin >> n;
    while (n--) r = (r * 2) % 1000000007;
    std::cout << r;
}