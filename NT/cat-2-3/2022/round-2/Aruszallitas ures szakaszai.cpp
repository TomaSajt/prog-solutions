#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    while (m--) {
        int l, r;
        cin >> l >> r;
        v[l - 1]++;
        v[r - 1]--;
    }
    partial_sum(v.begin(), v.end(), v.begin());
    int c = 0;
    if (v[0] == 0) c++;
    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1] != 0 && v[i] == 0) c++;
    }
    cout << c;
}