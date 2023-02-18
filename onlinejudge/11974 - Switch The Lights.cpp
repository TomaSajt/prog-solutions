#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;


int solve(int n, int m) {
    vector<int> switches(m);
    for (int& sw : switches) {
        for (int i = 0; i < n; i++) {
            bool b; cin >> b;
            sw = (sw << 1) | b;
        }
    }
    queue<int> q;
    vector<int> dist(1 << n, INT_MAX);
    dist[(1 << n) - 1] = 0;
    q.push((1 << n) - 1);
    while (!q.empty()) {
        int currState = q.front(); q.pop();
        for (auto& sw : switches) {
            int nextState = currState ^ sw;
            if (dist[nextState] != INT_MAX) continue;
            dist[nextState] = dist[currState] + 1;
            q.push(nextState);
        }
    }
    return dist[0];
}

int main() {
    speed;
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, m;
        cin >> n >> m;
        cout << "Case " << i << ": ";
        int res = solve(n, m);
        if (res == INT_MAX) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }
}