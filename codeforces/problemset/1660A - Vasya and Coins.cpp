#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
int main() {
    speed;
    int a, b;
    cin >> a;
    while (cin >> a >> b) {
        cout << (a == 0 ? 1 : a + 2 * b + 1) << endl;
    }
}