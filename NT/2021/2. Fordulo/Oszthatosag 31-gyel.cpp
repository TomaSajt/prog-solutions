#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    cout << (n % 31 == 0 ? "IGEN" : "NEM") << '\n';
    while (n > 0) {
        n = n / 10 - 3 * (n % 10);
        if (n >= 0) cout << n << ' ';
    }
    cout << '\n';
}