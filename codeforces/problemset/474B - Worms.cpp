#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int n, q;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1;i <= n;i++) cin >> v[i], v[i] += v[i - 1];
    cin >> q;
    while (cin >> q) {
        cout << lower_bound(v.begin(), v.end(), q) - v.begin() << endl;
    }

}