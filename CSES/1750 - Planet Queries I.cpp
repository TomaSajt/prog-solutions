
#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int jump[200001][31];

int main() {
    speed;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> jump[i][0];
    }
    for (int j = 1; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 30; i >= 0; i--) {
            if ((k >> i) & 1) {
                x = jump[x][i];
            }
        }
        cout << x << endl;
    }
}
