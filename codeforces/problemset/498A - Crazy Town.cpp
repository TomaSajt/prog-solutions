#include <bits/stdc++.h>
#define int long long
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;


int sign(int n) {
    return (n > 0) - (n < 0);
}

signed main() {
    speed;
    int sx, sy, ex, ey, n;
    cin >> sx >> sy >> ex >> ey >> n;
    int res = 0;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        int u = sign(a * sx + b * sy + c);
        int v = sign(a * ex + b * ey + c);
        if (u != v) res++;
    }
    cout << res;
}