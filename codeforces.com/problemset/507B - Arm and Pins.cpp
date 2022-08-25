#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r, x, y, x2, y2;
    cin >> r >> x >> y >> x2 >> y2;
    x -= x2;
    y -= y2;
    cout << ceil(sqrt(x * x + y * y) / (2 * r)) << endl;
}