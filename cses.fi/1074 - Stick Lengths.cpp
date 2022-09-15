#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto& p : v) {
        cin >> p;
        m[p]++;
    }
    auto lit = m.begin(), rit = --m.end();
    while (lit != rit) {
        int lv = lit->second, rv = rit->second;
        if (lv < rv) (++lit)->second += lv;
        else (--rit)->second += rv;
    }
    int x = lit->first;
    long long res = 0;
    for (auto& p : v) res += abs(p - x);
    cout << res;
}