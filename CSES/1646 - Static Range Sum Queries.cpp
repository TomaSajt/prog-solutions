#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, a, b;
    cin >> n >> a;
    vector<long long> v(n), p(n + 1);
    for (auto& x : v) cin >> x;
    partial_sum(v.begin(), v.end(), p.begin() + 1);
    while (cin >> a >> b) cout << p[b] - p[a - 1] << '\n';
}