#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto& p : v) cin >> p;
    sort(v.begin(), v.end());
    int x = v[(n - 1) / 2];
    long long res = 0;
    for (auto& p : v) res += abs(p - x);
    cout << res;
}