// 7/100
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> V(N);
    for (int& x : V) cin >> x;
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        X--, Y--;
        queue<int> q;
        vector<int> vis(N), d(N, INF);
        vis[X] = 1;
        d[X] = 0;
        q.push(X);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < N; v++) {
                if ((V[u] & V[v]) != 0 && !vis[v]) {
                    vis[v] = 1;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        cout << (d[Y] == INF ? -1 : d[Y]) << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
