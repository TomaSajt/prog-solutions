#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    for (cin >> n; cin >> n;) {
        vector<int> a(n), b(n);
        for (auto& i : a) cin >> i;
        for (auto& i : b) cin >> i;
        int ca = count(a.begin(), a.end(), 1);
        int cb = count(b.begin(), b.end(), 1);
        if (ca < cb) swap(a, b), swap(ca, cb);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (!a[i] && b[i]) {
                r = 1;
                break;
            }
        }
        cout << ca - cb + r << '\n';
    }
}