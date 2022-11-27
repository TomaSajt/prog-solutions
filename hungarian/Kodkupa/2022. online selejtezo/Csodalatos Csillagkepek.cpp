#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    map<int, int> xc, yc;
    vector<pair<int, int>> pts(n);
    for (auto& [x, y] : pts) {
        cin >> x >> y;
        xc[x]++;
        yc[y]++;
    }
    long long res = 0;
    for (auto& [x, y] : pts) {
        res += (xc[x] - 1ll) * (yc[y] - 1);
    }
    cout << res;
}