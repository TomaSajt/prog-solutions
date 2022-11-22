#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef unsigned long long ull;

int popcount(ull n) {
    int res = 0;
    for (int i = 0; i < 64; i++) res += (n >> i) & 1;
    return res;
}

ull ne(ull n) {
    ull p1 = n & -n;
    ull m = n + p1 - 1; // right of the first 1 is all 1s
    ull p0 = ~m & (m + 1); // position of first 0 after the first bunch of 1
    ull masked = n & (p0 - 1);
    int c = popcount(masked) - 1;
    ull res = n - masked + p0 + (1ull << c) - 1;
    return res;
}

int main() {
    speed;
    ull n; cin >> n;
    ull pr = ~ne(~n);
    if ((pr >> 63) & 1) cout << "-1";
    else cout << pr;
    cout << '\n' << ne(n);
}