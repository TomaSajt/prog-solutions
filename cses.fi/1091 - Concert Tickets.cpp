#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> req(m);
    multiset<int, greater<int>> tickets;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        tickets.insert(u);
    }
    for (auto& u : req) cin >> u;
    for (int i = 0; i < m; i++) {
        if (tickets.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto it = tickets.lower_bound(req[i]);
        if (it == tickets.end()) {
            cout << -1 << '\n';
            continue;
        }
        cout << *it << '\n';
        tickets.erase(it);
    }
}