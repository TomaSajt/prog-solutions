#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<set<int>> graf;
vector<int> ut;

void keres(int akt) {
    vector<int> indit;
    while (!graf[akt].empty()) {
        int x = *graf[akt].begin();
        graf[akt].erase(x);
        keres(x);
    }
    ut.push_back(akt);
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    graf.assign(n + 1, {});
    vector<int> indeg(n + 1), outdeg(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a].insert(b);
        indeg[b]++;
        outdeg[a]++;
    }
    for (int i = 1; i <= n; i++) {
        int d = outdeg[i] - indeg[i];
        if (i == 1) {
            if (d != 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        else if (i == n) {
            if (d != -1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
        else {
            if (d != 0) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    keres(1);
    reverse(ut.begin(), ut.end());
    if ((int)ut.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int x : ut) {
        cout << x << " ";
    }
    cout << '\n';
}