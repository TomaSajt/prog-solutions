#include <bits/stdc++.h>
using namespace std;

int main() {
    int y1, y2;
    char c1, c2; cin >> c1 >> y1 >> c2 >> y2;
    int x1 = c1 - 'a', x2 = c2 - 'a';
    cout << max(abs(x1 - x2), abs(y1 - y2)) << endl;
    while (x1 != x2 || y1 != y2) {
        if (x1 > x2) x1--, cout << 'L';
        else if (x1 < x2) x1++, cout << 'R';
        if (y1 > y2) y1--, cout << 'D';
        else if (y1 < y2) y1++, cout << 'U';
        cout << '\n';
    }
}