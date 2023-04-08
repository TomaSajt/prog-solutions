#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int base;
map<pair<int, ll>, ll> mem;

// I have no idea how this works, just started messing around with formulas on
// OEIS and got this working

// calculates the number of `d` digits used from `1..n`
ll num_of_digits_upto(int d, ll n) {
  if (n <= 0)
    return 0;
  if (mem.count({d, n}))
    return mem.at({d, n});
  ll r = n % base;
  ll q = n / base;
  ll res = q + (r + 1) * num_of_digits_upto(d, q) +
           (base - r - 1) * num_of_digits_upto(d, q - 1);
  if (d != 0 && r >= d)
    res++;
  return mem[pair<int, ll>(d, n)] = res;
}

int main() {
  cin >> base;
  vector<ll> budget(base);
  for (auto &b : budget)
    cin >> b;
  auto is_enough = [&](ll n) {
    for (int d = 0; d < base; d++) {
      if (num_of_digits_upto(d, n) > budget[d])
        return false;
    }
    return true;
  };

  ll curr = 0;
  for (int i = 55; i >= 0; i--) {
    ll next = curr + (1ll << i);
    if (is_enough(next))
      curr = next;
  }
  cout << curr;
}
