#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    map<int, int> t;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        t[a] = i;
    }
    int res = INT_MAX;
    for (auto& [k, v] : t) {
        if (res > v) res = v;
    }
    cout << res;
}