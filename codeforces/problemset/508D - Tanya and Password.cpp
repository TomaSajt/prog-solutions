#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;


map<string, multiset<string>> g;
map<string, int> degdiff;
vector<string> path;

void dfs(string u) {
    while (!g[u].empty()) {
        auto it = g[u].begin();
        string v = *it;
        g[u].erase(it);
        dfs(v);
    }
    path.push_back(u);
}

int main() {
    speed;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string u = s.substr(0, 2);
        string v = s.substr(1, 2);
        g[u].insert(v);
        degdiff[u]++;
        degdiff[v]--;
    }
    string start = "";
    for (auto [k, d] : degdiff) {
        if (abs(d) > 1) {
            cout << "NO";
            return 0;
        }
        if (d == 1) {
            if (start != "") {
                cout << "NO";
                return 0;
            }
            start = k;
        }
    }
    if (start == "") start = degdiff.begin()->first;
    dfs(start);
    if (path.size() != n + 1) {
        cout << "NO";
        return 0;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << path[0][0];
    for (auto& u : path) cout << u[1];
}