#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n;
    while (cin >> n >> m) {
        cout << (m < n ? "YES" : "NO") << '\n';
        while (m--) cin >> n >> n;
    }
}