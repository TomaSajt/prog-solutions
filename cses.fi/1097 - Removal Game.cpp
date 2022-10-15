#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long diff[5000][5000], v[5000], sum = 0;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        diff[i][i] = v[i];
    }
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            diff[l][r] = max(v[l] - diff[l + 1][r], v[r] - diff[l][r - 1]);
        }
    }
    cout << (sum + diff[0][n - 1]) / 2;
}