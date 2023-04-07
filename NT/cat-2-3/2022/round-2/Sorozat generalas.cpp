#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
#define int long long

int pows[13] = { 1 };
signed main() {
    speed;
    int m, x, a, b, n, k;
    cin >> m >> x >> a >> b >> n >> k;
    for (int i = 1; i <= 12; i++) pows[i] = pows[i - 1] * 10;
    map<int, int> im;
    vector<int> s;
    int r = -1;
    for (int i = 0; i < n; i++) {
        x = ((a * x + b) / pows[m]) % pows[2 * m];
        if (r == -1 && im.count(x)) r = i - im[x];
        s.push_back(x);
        im[x] = i;
    }
    sort(s.begin(), s.end());
    cout << r << '\n' << s[n - k];
}