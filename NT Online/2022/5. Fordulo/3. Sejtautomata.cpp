// 100/100

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")

using namespace std;
int main() {
    speed;
    int n, k;
    cin >> n >> k;
    vector<bool> prev(n);
    for (int i = 0;i < n;i++) {
        char c;
        cin >> c;
        prev[i] = c == 'Z';
    }
    int m;
    cin >> m;
    vector<vector<bool>> patterns(m, vector<bool>(5));
    for (auto& pat : patterns) {
        for (int i = 0;i < 5;i++) {
            char c;
            cin >> c;
            pat[i] = c == 'Z';
        }
    }

    while (k--) {
        vector<bool> curr(n);
        for (int i = 0; i < n - 4; i++) {
            for (auto& pat : patterns) {
                bool b = true;
                for (int j = 0;j < 5;j++) {
                    if (prev[i + j] != pat[j]) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    curr[i + 2] = true;
                    break;
                }
            }
        }
        if (prev == curr) break;
        swap(prev, curr);
    }
    cout << count(prev.begin(), prev.end(), true) << '\n';

}
