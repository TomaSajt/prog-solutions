#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        v[i] = c == '1' ? 1 : 0;
    }
    int cnts[2] = { 0,0 };
    cnts[v[0]]++;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] != v[i]) cnts[v[i]]++;
    }
    cout << (cnts[0] + cnts[1]) / 2 << '\n';
    while (q--) {
        int k; cin >> k; k--;
        if (k == 0) {
            if (v[0] == v[1]) cnts[1 - v[0]]++;
            else cnts[v[0]]--;
        }
        else if (k == n - 1) {
            if (v[n - 1] == v[n - 2]) cnts[1 - v[n - 1]]++;
            else cnts[v[n - 1]]--;
        }
        else if (v[k - 1] == v[k + 1]) {
            if (v[k] == v[k - 1]) cnts[0]++, cnts[1]++;
            else cnts[0]--, cnts[1]--;
        }
        v[k] = 1 - v[k];
        cout << (cnts[0] + cnts[1]) / 2 << '\n';
    }
}