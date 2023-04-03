#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    while (m--) {
        vector<int> a(n);
        for (int& e : a) cin >> e;
        a.pb(-1);
        vector<int> b;
        int c = 0;
        for (int i = 0; i < n;i++) {
            c++;
            if (a[i] != a[i + 1]) {
                b.pb(c);
                c = 0;
            }
        }
        int l = b.size();
        vector<bool> DP(l);
        DP[l - 1] = true;
        for (int i = l - 2; i >= 0;i--) {
            DP[i] = !DP[i + 1];
            if (b[i] > 1) {
                DP[i] = true;
            }
        }
        cout << (DP[0] ? "IGEN" : "NEM") << " ";
        for (int i = 0; i < l - 1;i++) {
            if (b[i] == 1) cout << "1 ";
            else {
                if (DP[i] == DP[i + 1]) {
                    cout << b[i] - 1 << " 1 ";
                }
                else {
                    cout << b[i] << " ";
                }
            }
        }
        cout << b[l - 1] << endl;
    }
}
/*

    solve(i) => a[i]==1 ? !solve(i+1) : true||solve!
*/