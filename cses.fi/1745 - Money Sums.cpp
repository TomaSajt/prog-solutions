#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    set<int> s, s2;
    s.insert(0);
    s2 = s;
    for (int i = 0; i < n; i++, s = s2) {
        for (int a : s) s2.insert(a + v[i]);
    }
    s.erase(0);
    cout << s.size() << '\n';
    for (int a : s) cout << a << ' ';
}