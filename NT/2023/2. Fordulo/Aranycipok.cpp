#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

int main() {
    speed;
    int n; cin >> n;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    int m = *max_element(v.begin(), v.end());
    vector<int> sol;
    for (int i = 0; i < n; i++) {
        if (v[i] == m) sol.push_back(i);
    }
    cout << m << '\n' << sol.size();
    for (auto i : sol) cout << '\n' << i + 1;
    return 0;
}
