#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> v{ "" };
    while (n--) {
        int m = v.size();
        vector<string> c(2 * m);
        for (int i = 0; i < m; i++) {
            c[i] = "0" + v[i];
            c[2 * m - 1 - i] = "1" + v[i];
        }
        v = c;
    }
    for (auto& s : v) cout << s << '\n';
}