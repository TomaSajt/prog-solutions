#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (size_t i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a > i) {
            g[i].push_back(a);
        }
        if (i != n) {
            g[i].push_back(i + 1);
        }
    }
    queue<int> q;
    vector<bool> vis(n + 1);
    vector<int> dist(n + 1);
    q.push(1);
    vis[1] = true;
    dist[1] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nei : g[curr]) {
            if (!vis[nei]) {
                vis[nei] = true;
                dist[nei] = dist[curr] + 1;
                q.push(nei);
            }
        }
    }
    cout << dist[n] << endl;


    return 0;




}