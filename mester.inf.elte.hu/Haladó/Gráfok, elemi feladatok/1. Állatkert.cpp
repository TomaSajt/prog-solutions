#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main() {
    speed;
    int n, m, c;
    cin >> n >> m;
    vector<int> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u]++, g[v]++;
    }
    cout << count_if(g.begin(), g.end(), [](int x) {return x == 1;}) << " " << max_element(g.begin(), g.end()) - g.begin();
}