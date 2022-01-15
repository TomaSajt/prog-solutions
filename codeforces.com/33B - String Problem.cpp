#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2, s = "";
    cin >> s1 >> s2;

    int n;
    cin >> n;

    vector<vector<int>> g(26, vector<int>(26, INT_MAX / 2));

    for (int i = 0; i < n; i++) {
        char c1, c2;
        int w;
        cin >> c1 >> c2 >> w;
        if (w < g[c1 - 'a'][c2 - 'a']) {
            g[c1 - 'a'][c2 - 'a'] = w;
        }
    }

    if (s1.size() != s2.size()) {
        cout << -1 << endl;
        return 0;
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) g[i][i] = 0;

    long long cost = 0;
    for (int i = 0; i < s1.size(); i++) {
        int e1 = s1[i] - 'a', e2 = s2[i] - 'a';
        if (e1 != e2) {
            int min = INT_MAX, minid = -1;
            for (int j = 0; j < 26; j++) {
                if (g[e1][j] == INT_MAX / 2 || g[e2][j] == INT_MAX / 2) continue;
                if (g[e1][j] + g[e2][j] < min) {
                    min = g[e1][j] + g[e2][j];
                    minid = j;
                }
            }

            if (minid == -1) {
                cout << -1 << endl;
                return 0;
            }

            cost += min;
            s += minid + 'a';
        }
        else {
            s += s1[i];
        }
    }

    cout << cost << endl << s << endl;
}