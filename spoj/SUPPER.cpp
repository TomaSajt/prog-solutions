#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    for (int t = 1; t <= 10; t++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& a : v) cin >> a;
        vector<int> dp;
        vector<int> len(n, 1); // longest increasing subsequence containing the ith element
        for (int i = 0; i < n; i++) {
            int a = v[i];
            auto it = lower_bound(dp.begin(), dp.end(), a, less<int>{});
            len[i] += it - dp.begin();
            if (it == dp.end()) dp.push_back(a);
            else *it = a;
        }
        dp.clear();
        for (int i = n - 1; i >= 0; i--) {
            int a = v[i];
            auto it = lower_bound(dp.begin(), dp.end(), a, greater<int>{});
            len[i] += it - dp.begin();
            if (it == dp.end()) dp.push_back(a);
            else *it = a;
        }
        int maxval = *max_element(len.begin(), len.end());
        set<int> res;
        for (int i = 0; i < n; i++) {
            if (len[i] == maxval) res.insert(v[i]);
        }
        cout << res.size() << '\n';
        for (int a : res) cout << a << ' ';
        cout << '\n';
    }
}
