#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll MAX_X = 1e6;
const ll MAX_Y = 1e6;
const ll FMN = MAX_Y + 19 - 1; // 19 = log2(MAX_X)

bool is_prime[MAX_X + 1];
vector<ll> primes;
ll fact[FMN + 1], i_fact[FMN + 1], _2pow[MAX_Y];

ll mul(ll a, ll b) { return a * b % MOD; }
ll powi(ll a, ll b) { return b == 0 ? 1 : mul(powi(mul(a, a), b / 2), b % 2 == 1 ? a : 1); }
ll choose(ll n, ll k) { return mul(mul(fact[n], i_fact[k]), i_fact[n - k]); }

ll solve(ll x, ll y) {
  ll res = _2pow[y - 1];
  for (ll p : primes) {
    if (x == 1) return res;
    ll c = 0;
    if (is_prime[x]) x = 1, c = 1;
    while (x % p == 0) x /= p, c++;
    res = mul(res, choose(c + y - 1, c));
  }
  return -1;
}

int main() {
  // init primes
  fill(is_prime + 2, is_prime + MAX_X + 1, 1);
  for (ll i = 2; i <= MAX_X; i++) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for (ll j = i * i; j <= MAX_X; j += i) is_prime[j] = 0;
  }
  // init powers of two
  _2pow[0] = 1;
  for (ll i = 1; i < MAX_Y; i++) _2pow[i] = mul(_2pow[i - 1], 2);
  // init factorials
  fact[0] = 1;
  for (ll i = 1; i <= FMN; i++) fact[i] = mul(fact[i - 1], i);
  // init multiplicative inverses of factorials
  i_fact[FMN] = powi(fact[FMN], MOD - 2);
  for (ll i = FMN; i >= 1; i--) i_fact[i - 1] = mul(i_fact[i], i);
  // process input
  ll t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> x >> y;
    cout << solve(x, y) << '\n';
  }
}
