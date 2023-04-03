#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    speed;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> solutions(n, -1);
    vector<vector<int>> gt(n);
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) gt[i - a[i]].pb(i);
        if (i + a[i] < n) gt[i + a[i]].pb(i);
    }
    vector<bool> vis(n);
    vector<int> dist(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            vis[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (solutions[curr] == -1) solutions[curr] = a[curr] % 2 == 0 ? -1 : dist[curr];
        for (auto&& nei : gt[curr]) {
            if (vis[nei]) continue;
            vis[nei] = true;
            q.push(nei);
            dist[nei] = dist[curr] + 1;
        }
    }
    vis.assign(n, 0);
    dist.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            vis[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (solutions[curr] == -1) solutions[curr] = a[curr] % 2 == 1 ? -1 : dist[curr];
        for (auto&& nei : gt[curr]) {
            if (vis[nei]) continue;
            vis[nei] = true;
            q.push(nei);
            dist[nei] = dist[curr] + 1;
        }
    }
    for (auto&& i : solutions) {
        cout << i << ' ';
    }
    cout << endl;
}