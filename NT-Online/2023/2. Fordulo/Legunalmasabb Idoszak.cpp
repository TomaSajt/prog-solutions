#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int& a : v) cin >> a;
    int cnt = 0;
    vector<int> typeCnt(m + 1);
    auto inc = [&](int t) {
        if (t == 0) return;
        if (typeCnt[t]++ == 0) cnt++;
    };
    auto dec = [&](int t) {
        if (t == 0) return;
        if (--typeCnt[t] == 0) cnt--;
    };
    for (int i = 0; i < k; i++) inc(v[i]);
    int bestI = 0;
    int bestCnt = cnt;
    for (int i = 1; i <= n - k; i++) {
        dec(v[i - 1]);
        inc(v[i + k - 1]);
        if (bestCnt > cnt) {
            bestCnt = cnt;
            bestI = i;
        }
    }
    cout << bestI + 1;
}