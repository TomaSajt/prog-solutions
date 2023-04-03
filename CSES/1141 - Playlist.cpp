#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, l = 0, r = 0, m = 1;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for (auto& k : v) cin >> k;
    while (r < n) {
        if (s.count(v[r])) {
            while (v[l] != v[r]) s.erase(v[l++]);
            l++;
        }
        m = max(m, r - l + 1);
        s.insert(v[r++]);
    }
    cout << m;
}