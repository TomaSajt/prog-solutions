#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6;

// uses inclusion-exclusion principle
int divisible_composites_upto(int n, const vector<int>& primes) {
  int k = primes.size();
  int divisible = 0;
  for (int i = 1; i < (1 << k); i++) {
    int prod = 1;
    for (int j = 0; j < k; j++) {
      if (i >> j & 1) prod *= primes[j];
      if (prod > n) break; // avoid overflow and unnecessary computations
    }
    int sign = __builtin_popcount(i) % 2 == 0 ? -1 : 1;
    divisible += (n / prod) * sign;
  }
  int included_primes = count_if(primes.begin(), primes.end(), [&](int p) { return p <= n; });
  return divisible - included_primes;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  vector<int> is_composite(maxN + 1);
  for (int i = 2; i <= maxN; i++) {
    if (is_composite[i]) continue;
    for (int j = 2 * i; j <= maxN; j += i) is_composite[j] = 1;
  }

  vector<int> composites_upto(maxN + 1);
  partial_sum(is_composite.begin(), is_composite.end(), composites_upto.begin());

  int q;
  cin >> q;
  for (int t = 1; t <= q; t++) {
    int n, k;
    cin >> n >> k;
    vector<int> primes(k);
    for (int& p : primes) cin >> p;
    cout << "Case " << t << ": " << composites_upto[n] - divisible_composites_upto(n, primes) << '\n';
  }
}
