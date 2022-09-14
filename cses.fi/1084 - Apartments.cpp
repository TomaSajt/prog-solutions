#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& u : a) cin >> u;
    sort(a.begin(), a.end());
    for (auto& u : b) cin >> u;
    sort(b.begin(), b.end());
    int i = 0, j = 0, s = 0;
    while (i < n && j < m) {
        if (b[j] < a[i] - k) j++;
        else if (b[j] > a[i] + k) i++;
        else i++, j++, s++;
    }
    cout << s;
}