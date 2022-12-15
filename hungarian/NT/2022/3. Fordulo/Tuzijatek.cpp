#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<int> res;
    res.push_back(s);
    int lastPos = v[s];
    for (int i = s - 1; i >= 1; i--) {
        if (lastPos - v[i] < t) continue;
        lastPos = v[i];
        res.push_back(i);
    }
    lastPos = v[s];
    for (int i = s + 1; i <= n; i++) {
        if (v[i] - lastPos < t) continue;
        lastPos = v[i];
        res.push_back(i);
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto a : res) cout << a << ' ';
}