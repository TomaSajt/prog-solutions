#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        auto [s, e] = minmax(i, a);
        v[s]++;
        v[e]--;
    }
    for (int i = 2; i <= n; i++) v[i] += v[i - 1];
    auto it = max_element(v.begin() + 1, v.end());
    cout << *it << '\n' << it - v.begin();
}