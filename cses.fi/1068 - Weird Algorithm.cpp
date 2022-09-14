#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    long long n;
    cin >> n;
    while (n > 1) {
        cout << n << ' ';
        n = n % 2 == 0 ? n / 2 : 3 * n + 1;
    }
    cout << 1;
}