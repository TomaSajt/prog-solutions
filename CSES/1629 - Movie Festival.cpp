#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [b, a] : v) cin >> a >> b;
    sort(v.begin(), v.end());
    int t = 0, c = 0;
    for (auto& [b, a] : v) {
        if (a >= t) {
            t = b;
            c++;
        }
    }
    cout << c;
}