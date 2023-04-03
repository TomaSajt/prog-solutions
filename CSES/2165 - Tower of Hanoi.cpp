#include <bits/stdc++.h>
using namespace std;

void solve(int n, int from, int to, int use) {
    if (n == 0) return;
    solve(n - 1, from, use, to);
    cout << from << ' ' << to << '\n';
    solve(n - 1, use, to, from);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cout << (1 << n) - 1 << '\n';
    solve(n, 1, 3, 2);
}