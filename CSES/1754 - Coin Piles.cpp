#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int a, b;
    cin >> a;
    while (cin >> a >> b) {
        if (a < b) swap(a, b);
        int diff = a - b;
        cout << (b - diff < 0 || (b - diff) % 3 != 0 ? "NO" : "YES") << '\n';
    }
}