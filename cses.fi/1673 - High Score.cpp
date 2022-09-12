#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge { int u, v; ll w; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> score(n + 1, LLONG_MIN / 2);
    vector<bool> reachn(n + 1), rreach1(n + 1);
    vector<edge> edges(m);
    score[1] = 0;
    reachn[n] = 1;
    rreach1[1] = 1;
    for (auto& e : edges) cin >> e.u >> e.v >> e.w;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            reachn[u] = reachn[u] || reachn[v];
            rreach1[v] = rreach1[v] || rreach1[u];
            ll a = score[u] + w;
            if (score[v] < a) {
                score[v] = a;
                if (i == n - 1 && reachn[v] && rreach1[v]) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << score[n];
}