#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> gt(n);
    vector<int> deps(n), a(n);
    priority_queue<int> zdeps;
    while (cin >> u >> v) gt[--v].push_back(--u), deps[u]++;
    for (int i = 0; i < n; ++i) if (!deps[i]) zdeps.push(i);
    for (int j = n, i; j; --j) {
        i = zdeps.top(); zdeps.pop();
        a[i] = j;
        for (int v : gt[i]) if (!--deps[v]) zdeps.push(v);
    }
    for (int i : a) cout << i << ' ';
}