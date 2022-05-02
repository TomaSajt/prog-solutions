#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int q;
    cin >> q;
    string s, t;
    while (cin >> s >> t) {
        if (t == "a") {
            cout << 1 << endl;
            continue;
        }
        if (t.find('a') != t.npos) {
            cout << -1 << endl;
            continue;
        }
        cout << (1ull << s.size()) << endl;
    }

}