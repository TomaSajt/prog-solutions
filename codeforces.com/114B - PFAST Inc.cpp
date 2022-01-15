#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> nevek(n);
    map<string, int> rnevek;
    for (int i = 0; i < n; i++) {
        cin >> nevek[i];
        rnevek[nevek[i]] = i;
    }

    vector<vector<bool>> szeret(n, vector<bool>(n, true));
    for (int i = 0; i < m; i++) {
        string ast, bs;
        cin >> ast >> bs;
        int a = rnevek[ast], b = rnevek[bs];
        szeret[a][b] = false;
        szeret[b][a] = false;
    }

    uint32_t cmax = (1 << n) - 1;

    int max = 0, maxval = 0;
    for (unsigned c = 1; c <= cmax; c++) {
        int bc = 0;
        for (int i = 0; i < n; i++) {
            if ((c >> i) & 1) bc++;
        }
        if (bc <= max) continue;

        bool jo = true;
        for (int i = 0; i < n && jo; i++) {
            for (int j = 0; j < n && jo; j++) {
                if (((c >> i) & 1) && ((c >> j) & 1)) {
                    if (!szeret[i][j]) {
                        jo = false;
                    }
                }
            }
        }

        if (jo) {
            max = bc;
            maxval = c;
        }
    }

    vector<string> eredmeny;

    cout << max << endl;
    for (int i = 0; i < n; i++) {
        if ((maxval >> i) & 1) {
            eredmeny.push_back(nevek[i]);
        }
    }

    sort(eredmeny.begin(), eredmeny.end());

    for (string& s : eredmeny) cout << s << endl;
}