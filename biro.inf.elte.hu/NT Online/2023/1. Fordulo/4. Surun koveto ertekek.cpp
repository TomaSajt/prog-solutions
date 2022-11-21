#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    map<int, int> lastSeen;
    set<int> res;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (lastSeen.count(a) && i - lastSeen[a] <= k) res.insert(a);
        lastSeen[a] = i;
    }
    cout << res.size() << '\n';
    for (auto a : res) cout << a << ' ';
}