#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    string s;
    cin >> s;
    vector<int> l(26);
    for (char c : s) l[c - 'A']++;
    int odd = -1;
    for (int i = 0; i < 26; i++) {
        if (l[i] % 2 == 0) continue;
        if (odd != -1) {
            cout << "NO SOLUTION";
            return 0;
        }
        odd = i;
    }
    for (int i = 0; i < 26; i++) {
        if (i == odd) continue;
        cout << string(l[i] / 2, 'A' + i);
    }
    if (odd != -1) cout << string(l[odd], 'A' + odd);
    for (int i = 25; i >= 0; i--) {
        if (i == odd) continue;
        cout << string(l[i] / 2, 'A' + i);
    }

}