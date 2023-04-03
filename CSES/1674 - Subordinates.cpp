#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> deg(n + 1), par(n + 1), ch(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        deg[par[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == 1) break;
        int v = par[u];
        ch[v] += ch[u] + 1;
        if (--deg[v] == 0) q.push(v);
    }
    for (int i = 1; i <= n; i++) cout << ch[i] << ' ';
}