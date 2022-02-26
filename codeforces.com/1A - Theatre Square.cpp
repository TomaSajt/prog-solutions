#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int main() {
    speed;
    long long n, m, a;
    cin >> n >> m >> a;
    cout << ((n - 1) / a + 1) * ((m - 1) / a + 1) << endl;
}