#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

struct edge {
    int from, to;
    ll w;
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<ll> dist(n + 1);
    vector<ll> parent(n + 1);
    vector<edge> edges(m);
    for (auto& e : edges) cin >> e.from >> e.to >> e.w;
    bool neg_cycle = false;
    int last_updated;
    for (int i = 0; i < n; i++) {
        for (auto& e : edges) {
            if (dist[e.from] + e.w < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.w;
                parent[e.to] = e.from;
                last_updated = e.to;
                neg_cycle = i == n - 1;
            }
        }
    }
    cout << (neg_cycle ? "YES" : "NO") << endl;
    if (neg_cycle) {
        set<int> seen;
        stack<int> s;
        int curr = last_updated;
        while (seen.find(curr) == seen.end()) {
            s.push(curr);
            seen.insert(curr);
            curr = parent[curr];
        }
        int end = curr;
        cout << end << ' ';
        while (s.top() != end) {
            cout << s.top() << ' ';
            s.pop();
        }
        cout << end << endl;
    }
    return 0;
}