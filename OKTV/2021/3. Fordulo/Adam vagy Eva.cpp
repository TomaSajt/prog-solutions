#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;


int main() {
    speed;
    vector<pair<int, int>> ivs;
    int n; cin >> n;
    for (int i = 0; i < 2; i++) {
        cin >> n;
        while (n--) {
            auto& [l, r] = ivs.emplace_back();
            cin >> l >> r;
        }
    }
    sort(ivs.rbegin(), ivs.rend());
    stack<pair<int, int>> s;
    vector<pair<int, int>> res;
    for (auto iv : ivs) s.push(iv);
    while (s.size() >= 2) {
        auto [la, ra] = s.top(); s.pop();
        auto [lb, rb] = s.top(); s.pop();
        if (ra >= lb) s.push({ la, max(ra,rb) });
        else res.push_back({ la,ra }), s.push({ lb,rb });
    }
    if (s.size() == 1) res.push_back(s.top());
    cout << res.size() << '\n';
    for (auto [l, r] : res) cout << l << ' ' << r << '\n';
}