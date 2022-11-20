#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, base;
    cin >> n >> base;
    int minGreater = INT_MAX;
    int maxLess = 0;
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        if (a > base && a <= minGreater) minGreater = a;
        else if (a < base && a >= maxLess) maxLess = a;
        else if (a != base) res.push_back(i);
    }
    cout << res.size() << '\n';
    for (auto i : res) cout << i << ' ';
}