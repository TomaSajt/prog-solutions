#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)
const int mod = 1e9 + 7;

int main() {
    speed;
    int n; cin >> n;
    map<int, int> cnts;
    while (n--) {
        int a; cin >> a;
        cnts[a]++;
    }
    bool first = 1;
    long long res = 1;
    for (auto [x, c] : cnts) {
        if (first) {
            first = 0;
            continue;
        }
        res *= (c + 1);
        res %= mod;
    }
    cout << res;
    return 0;
}
