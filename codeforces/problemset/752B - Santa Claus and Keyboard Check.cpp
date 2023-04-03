#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    string s, t;
    cin >> s >> t;
    vector<pair<char, char>> p;
    map<char, char> m;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (!m.count(s[i]) && !m.count(t[i])) {
            m[s[i]] = t[i], m[t[i]] = s[i];
            if (s[i] != t[i]) {
                p.emplace_back(s[i], t[i]);
            }
        }
        else if (m.count(s[i])) {
            if (m[s[i]] != t[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
        else {
            if (m[t[i]] != s[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << p.size() << endl;
    for (auto [a, b] : p) cout << a << " " << b << endl;
}