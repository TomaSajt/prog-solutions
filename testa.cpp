#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 2; i <= 498;i++) {
        if ((4 * i * i) % 9 == 4) {
            cout << i << endl;
        }
    }
}
