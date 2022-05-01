#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    long long c;
    for (cin >> c;cin >> c;) {
        long long rc = sqrt(c) + 0.5;
        if (c == 1 || rc * rc != c) {
            cout << "NO" << endl;
            continue;
        };
        bool good = true;
        for (int i = 2; i * i <= rc;i++) {
            if (rc % i == 0) {
                good = false;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }

}