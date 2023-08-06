#include <bits/stdc++.h>
using namespace std;

int jump[200001][61];

int main() {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> jump[i][0];
    }
    for (int j = 1; j <= 60; j++) {
        for (int i = 1; i <= n; i++) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    int pos = 1;
    for (int i = 60; i >= 0; i--) {
        if ((1ull << i) & k) {
            pos = jump[pos][i];
        }
    }
    cout << pos << endl;
}
