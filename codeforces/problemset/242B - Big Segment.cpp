#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& v : a) cin >> v.first >> v.second;
    int s = min_element(a.begin(), a.end())->first;
    int e = max_element(a.begin(), a.end(), [](auto u, auto v) {return u.second < v.second;})->second;
    for (int i = 0; i < n;i++) {
        if (a[i].first == s && a[i].second == e) {
            cout << i + 1;
            return 0;
        }
    }
    cout << "-1";
}


/*#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> mins;
    unordered_set<int> maxes;
    int minV = 1000000000;
    int maxV = -1000000000;
    for (int i = 1; i <= n; i++) {
        int s, e;
        std::cin >> s >> e;
        if (s <= minV) {
            if (s != minV) {
                minV = s;
                mins.clear();
            }
            mins.insert(i);
        }
        if (e >= maxV) {
            if (e != maxV) {
                maxV = e;
                maxes.clear();
            }
            maxes.insert(i);
        }
    }
    for (auto max : maxes) {
        if (mins.find(max) != mins.end()) {
            cout << max << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}*/