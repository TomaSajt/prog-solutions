#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    int hn = n / 2;
    if (n % 4 == 0) {
        cout << "YES\n" << hn << '\n';
        for (int i = 1; i <= hn; i += 2) cout << i << ' ' << n - i + 1 << ' ';
        cout << '\n' << hn << '\n';
        for (int i = 2; i <= hn; i += 2) cout << i << ' ' << n - i + 1 << ' ';
    }
    else if (n % 4 == 3) {
        cout << "YES\n" << hn + 1 << '\n';
        for (int i = 1; i < hn; i += 2) cout << i << ' ' << n - i << ' ';
        cout << hn << ' ' << hn + 1 << '\n' << hn << '\n';
        for (int i = 2; i < hn; i += 2) cout << i << ' ' << n - i << ' ';
        cout << n;
    }
    else cout << "NO";
}