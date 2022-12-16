#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (i % 3 == 0 && i % 5 == 0) {
            if (s[1] != 'U') {
                cout << i;
                return 0;
            }
        }
        else if (i % 3 == 0) {
            if (s[1] != 'I') {
                cout << i;
                return 0;
            }
        }
        else if (i % 5 == 0) {
            if (s[1] != 'A') {
                cout << i;
                return 0;
            }
        }
        else {
            if (s[0] != 'S') {
                cout << i;
                return 0;
            }
        }

    }
    cout << "0";
}