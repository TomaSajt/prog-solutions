#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> stations(k);
    vector<vector<int>> graph(n + 1);
    for (auto& i : stations) cin >> i;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

}