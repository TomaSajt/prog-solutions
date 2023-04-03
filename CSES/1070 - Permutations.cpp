#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    if (n == 1) {
        cout << '1';
        return 0;
    }
    if (n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }
    int hn = (n + 1) / 2;
    cout << hn << ' ';
    for (int i = 1; i < hn; i++) cout << n - i + 1 << ' ' << i << ' ';
    if (n % 2 == 0) cout << hn + 1;
}