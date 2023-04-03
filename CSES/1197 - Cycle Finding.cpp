#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge { int u, v; ll w; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> prev(n + 1);
    vector<ll> dist(n + 1, LLONG_MAX / 2);
    vector<edge> edges(m);
    dist[1] = 0;
    for (auto& e : edges) cin >> e.u >> e.v >> e.w;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            ll a = dist[u] + w;
            if (dist[v] > a) {
                dist[v] = a;
                prev[v] = u;
                if (i == n - 1) {
                    int curr = v;
                    set<int> s;
                    vector<int> ord;
                    while (true) {
                        ord.push_back(curr);
                        if (s.count(curr)) break;
                        s.insert(curr);
                        curr = prev[curr];
                    }
                    reverse(ord.begin(), ord.end());
                    int l = find(ord.begin() + 1, ord.end(), ord[0]) - ord.begin();
                    cout << "YES\n";
                    for (int i = 0; i <= l; i++) cout << ord[i] << ' ';
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}