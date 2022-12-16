#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> dv(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        dv[u]++;
        dv[v]--;
    }

    int max = 0, curr = 0;
    for (int i = 0; i <= n; i++) {
        curr += dv[i];
        if (curr > max) max = curr;
    }
    cout << max;



}