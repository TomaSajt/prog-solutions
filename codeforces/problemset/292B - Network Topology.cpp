#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int n, m, a, b, c = -1;
    cin >> n >> m;
    vector<int> d(n + 1);
    while (cin >> a >> b) d[a]++, d[b]++;
    for (int i = 1; i <= n; i++) {
        if (d[i] < 3) continue;
        if (c != -1) {
            cout << "unknown topology" << endl;
            return 0;
        }
        c = i;
    }
    if (c != -1) {
        cout << (d[c] == m ? "star topology" : "unknown topology") << endl;
        return 0;
    }
    cout << (n == m ? "ring topology" : "bus topology") << endl;
    return 0;
}
