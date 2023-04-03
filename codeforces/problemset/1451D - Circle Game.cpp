#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef uint64_t ull;
bool check(ull p, ull q, ull d, ull k) {
    return (k * k) * (p * p + q * q) <= (d * d);
}
int main() {
    ull d, k;
    for (cin >> d; cin >> d >> k;) {
        ull a = 0;
        for (int i = 16; i >= 0; i--) {
            ull b = a + (1ull << i);
            if (check(b, b, d, k)) a = b;
        }
        cout << (check(a, a + 1, d, k) ? "Ashish\n" : "Utkarsh\n");
    }
}