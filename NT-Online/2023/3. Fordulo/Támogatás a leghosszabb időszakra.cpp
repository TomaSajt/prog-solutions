#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    vector<int> p(n);
    partial_sum(v.begin(), v.end(), p.begin());
    map<int, set<int>> valPositionsMap;
    for (int i = 0; i < n; i++) valPositionsMap[p[i]].insert(i);
    valPositionsMap[0].insert(-1);
    int bestD = -1;
    int bestI, bestJ;
    for (int i = 0; i < n; i++) {
        int target = p[i] - k;
        for (auto& j : valPositionsMap[target]) {
            if (j >= i) continue;
            if (bestD < i - j) {
                bestD = i - j;
                bestI = i;
                bestJ = j;
            }
        }
    }
    if (bestD == -1) cout << -1;
    else cout << bestJ + 2 << ' ' << bestI + 1;
}