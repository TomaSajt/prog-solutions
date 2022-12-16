// 65/100
#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;

vector<vector<pair<int, ll>>> neighbourS; // node, weight

void dijkstra(vector<ll>& distanceS, vector<int>& parentS, int s, int e) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> currentS; // distance, node
    distanceS[s] = 0;
    currentS.push({ 0, s });
    while (!currentS.empty()) {
        auto [currDist, currInd] = currentS.top();
        currentS.pop();
        if (currDist != distanceS[currInd]) {
            continue;
        }
        for (auto [nei, c] : neighbourS[currInd]) {
            if (distanceS[nei] == -1 || currDist + c < distanceS[nei]) {
                distanceS[nei] = currDist + c;
                currentS.push({ currDist + c, nei });
                parentS[nei] = currInd;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    neighbourS.resize(n);
    vector<pair<pair<int, int>, ll>> edges;
    while (m--) {
        int u, v; ll c;
        cin >> u >> v >> c;
        neighbourS[u].push_back({ v,c });
        neighbourS[v].push_back({ u,c });
        edges.push_back({ {u,v},c });
        edges.push_back({ {v,u},c });
    }
    vector<ll> distFromStart(n, -1), distFromEnd(n, -1);
    vector<int> parFromStart(n, -1), parFromEnd(n, -1);
    dijkstra(distFromStart, parFromStart, 0, n - 1);
    dijkstra(distFromEnd, parFromEnd, n - 1, 0);
    set<int> pathInds;
    ll pathDist = distFromStart[n - 1];
    int curr = n - 1;
    pathInds.insert(curr);
    while (parFromStart[curr] != -1) {
        curr = parFromStart[curr];
        pathInds.insert(curr);
    }
    ll best = LLONG_MAX;
    for (auto [pr, c] : edges) {
        auto [u, v] = pr;
        if (pathInds.count(u) && pathInds.count(v)) continue;
        ll val = pathDist - distFromStart[u] - distFromEnd[v] - 1;
        if (val > 0) best = min(best, c - val);
    }
    cout << (best == LLONG_MAX ? -1 : best);

}
