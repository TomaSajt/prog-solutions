#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

void solve() {
    vector<vector<int>> par(100001, vector<int>(18));
    set<int> inTree;

    int p; cin >> p;

    while (p--) {
        int x, y; cin >> x >> y;
        par[x][0] = y;
        inTree.insert(x);
    }
    for (int i = 1; i < 18; i++) {
        for (auto& node : inTree) {
            par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }
    
    int q; cin >> q;
    while (q--) {
        int o; cin >> o;
        if (o == 0) {
            int y, x; cin >> y >> x;
            inTree.insert(x);
            par[x][0] = y;
            for (int i = 1; i < 18; i++) {
                par[x][i] = par[par[x][i - 1]][i - 1];
            }
        }
        else if (o == 1) {
            int x; cin >> x;
            inTree.erase(x);
        }
        else if (o == 2) {
            int x, k; cin >> x >> k;
            if (inTree.count(x)) {
                for (int i = 0; i < 18; i++) {
                    if ((k >> i) & 1) {
                        x = par[x][i];
                    }
                }
                cout << x << '\n';
            }
            else cout << "0\n";
        }
    }
}

int main() {
    speed;
    int t; cin >> t;
    while (t--) solve();
}