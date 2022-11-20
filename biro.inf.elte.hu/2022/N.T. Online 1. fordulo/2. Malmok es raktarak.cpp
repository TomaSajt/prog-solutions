#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> v0, v1;
    for (int i = 0; i < 2 * n; i++) {
        int a; cin >> a;
        if (a == 0) v0.push_back(i);
        else v1.push_back(i);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(v0[i] - v1[i]);
    }
    cout << res;
}