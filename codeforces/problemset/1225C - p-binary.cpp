//stolen

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < 30; i++) {
        if (n - p * i >= (1 << i) - 1 && __builtin_popcount(n - p * i) <= i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}