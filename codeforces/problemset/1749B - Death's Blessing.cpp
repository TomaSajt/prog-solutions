#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    while (cin >> n) {
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            res += a;
        }
        int ma = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            res += a;
            ma = max(ma, a);
        }
        cout << res - ma << '\n';
    }
}