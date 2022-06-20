#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    speed;
    int n;
    cin >> n;
    vector<int> pies(n), f(n + 1), s(n + 1);
    for (int& p : pies) cin >> p;
    for (int i = n - 1; i >= 0; i--) {
        f[i] = s[i + 1] + pies[i];
        s[i] = f[i + 1];
        if (f[i] < s[i]) swap(f[i], s[i]);
    }
    cout << s[0] << ' ' << f[0];
}