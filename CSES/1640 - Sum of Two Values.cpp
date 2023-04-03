#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, x;
    cin >> n >> x;
    set<int> s;
    vector<int> v(n);
    for (auto& a : v) {
        cin >> a;
        if (s.find(a) != s.end()) {
            auto it1 = find(v.begin(), v.end(), a);
            auto it2 = find(a == x - a ? it1 + 1 : v.begin(), v.end(), x - a);
            cout << it1 - v.begin() + 1 << ' ' << it2 - v.begin() + 1;
            return 0;
        }
        s.insert(x - a);
    }
    cout << "IMPOSSIBLE";
}