using namespace std;
#include <bits/stdc++.h>
#define pb push_back

int main() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, long long>>> g(n + 1);
    set<int> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long l;
        cin >> u >> v >> l;
        g[u].pb({ v, l });
        g[v].pb({ u, l });
    }
    queue<int> nos;
    long long bestL = 1e10L;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (int st : s) {
        for (auto ne : g[st]) {
            if (s.find(ne.first) == s.end() && ne.second < bestL) {
                bestL = ne.second;
            }
        }
    }
    if (bestL == 1e10L)
        cout << "-1" << endl;
    else
        cout << bestL << endl;
    return 0;
}