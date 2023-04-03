#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y % x != 0) {
            cout << "0 0" << endl;
            continue;
        }
        cout << "1 " << y / x << endl;
    }

}