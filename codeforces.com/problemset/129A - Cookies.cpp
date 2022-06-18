#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    int n, a, o = 0, s = 0;
    cin >> n;
    while (cin >> a) {
        s += a;
        o += a % 2;
    }
    cout << (o % 2 == 0 ? n - o : o) << endl;
    return 0;
}