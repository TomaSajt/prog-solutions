#include <bits/stdc++.h>
using namespace std;

int main() {
    int rot, x, y;
    cin >> rot >> x >> y;
    double t = rot * 0.017453292519943295;
    cout << x * cos(t) - y * sin(t) << ' ' << y * cos(t) + x * sin(t);
}