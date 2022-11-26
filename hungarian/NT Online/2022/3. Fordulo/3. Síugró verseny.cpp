#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main() {
    speed;
    int n, m, p = 1;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1; i < m;i++) p += a[i] > a[m];
    for (int i = m; i <= n;i++) p += a[i] > a[m], b[p]++;
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
}