#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
long long memory[2001][2001], n, k;
int main() {
    speed;
    cin >> n >> k;
    for (int i = 1;i <= 2000;i++) {
        memory[i][0] = 1;
    }
    for (int l = 1; l <= k;l++) {
        for (int b = 1; b <= n; b++) {
            for (int i = 1; i * b <= n;i++) {
                memory[b][l] += memory[i * b][l - 1];
                memory[b][l] %= 1000000007;
            }
        }
    }
    cout << memory[1][k] << endl;
}
