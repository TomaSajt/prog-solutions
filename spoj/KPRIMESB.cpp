#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
vector<int> primes_to_n;

int solve(int n, int k, const vector<int>& kpr) {
    if (n < 2) return 0;
    int div = 0;
    for (int i = 1; i < (1 << k); i++) {
        int res = 1;
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) res *= kpr[j];
            if (res > n) break;
        }
        div += (__builtin_popcount(i) % 2 == 0 ? -1 : 1) * (n / res);
    }
    return n - div - primes_to_n[n] + k - 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> prime(maxN + 1, 1);
    prime[0] = prime[1] = 0;
    primes_to_n.resize(maxN + 1);
    for (int i = 2; i <= maxN;i++) {
        if (!prime[i]) continue;
        for (int j = 2; j * i <= maxN;j++) {
            prime[j * i] = 0;
        }
    }
    partial_sum(prime.begin(), prime.end(), primes_to_n.begin());
    int n, k, t = 1;
    cin >> n;
    while (cin >> n >> k) {
        vector<int> kpr(k);
        for (auto& i : kpr) cin >> i;
        cout << "Case " << t++ << ": " << solve(n, k, kpr) << '\n';
    }
}