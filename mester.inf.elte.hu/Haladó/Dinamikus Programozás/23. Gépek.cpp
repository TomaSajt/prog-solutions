#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int k, n, abt, bat, x;
    cin >> k >> n >> abt >> bat;
    vector<int> at(k + 1), bt(k + 1);
    for (int i = 1; i <= k; i++) cin >> at[i];
    for (int i = 1; i <= k; i++) cin >> bt[i];
    int a = 0, b = 0;
    while (cin >> x) {
        int u = min(a, b + bat) + at[x];
        int v = min(b, a + abt) + bt[x];
        a = u, b = v;
    }
    cout << min(a, b) << '\n';
}