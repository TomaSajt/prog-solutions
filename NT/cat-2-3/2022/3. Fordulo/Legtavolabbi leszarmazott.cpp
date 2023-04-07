#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> par(n + 1, -1);
    vector<vector<int>> children(n + 1);
    int u, v;
    while (cin >> u >> v) {
        par[v] = u;
        children[u].push_back(v);
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == -1) root = i;
    }
    queue<int> q;
    q.push(root);
    int last = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : children[u]) {
            q.push(v);
            last = v;
        }
    }
    cout << last;
}