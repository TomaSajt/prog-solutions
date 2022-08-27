#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a; cin >> n;
    vector<int> id(n + 1), sor;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        id[a] = n - i + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        a = id[a];
        auto it = lower_bound(sor.begin(), sor.end(), a);
        if (it == sor.end()) sor.push_back(a);
        else *it = a;
    }
    cout << sor.size();
}