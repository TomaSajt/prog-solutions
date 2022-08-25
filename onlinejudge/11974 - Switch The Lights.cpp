#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int k = 1; k <= t;k++) {
        int n, m;
        cin >> n >> m;
        vector<int> list(m);
        for (int& sw : list) {
            for (int i = 0; i < n;i++) {
                sw *= 2;
                bool b;
                cin >> b;
                sw += b;
            }
        }
        queue<int> q;
        vector<int> dist(1 << n, INT_MAX);
        dist[(1 << n) - 1] = 0;
        q.push((1 << n) - 1);
        while (!q.empty()) {
            int pos = q.front(); q.pop();
            for (int& sw : list) {
                int next = pos ^ sw;
                if (dist[next] == INT_MAX) {
                    dist[next] = dist[pos] + 1;
                    q.push(next);
                }
            }
        }
        cout << "Case " << k << ": ";
        if (dist[0] == INT_MAX) cout << "IMPOSSIBLE\n";
        else cout << dist[0] << '\n';
    }
}