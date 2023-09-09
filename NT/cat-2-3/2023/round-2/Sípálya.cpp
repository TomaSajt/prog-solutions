#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> range_maxes(const vector<ll>& v, int k) {
  int n = v.size();
  vector<ll> res(n - k + 1);
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
    while (!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();
    dq.push_back(i);
    if (i - k + 1 >= 0) {
      res[i - k + 1] = v[dq.front()];
    }
  }
  return res;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<ll> v(n);
  for (auto& a : v) cin >> a;
  for (int i = 0; i < n; i++) v[i] += i;  // add the index, so that we now need to make flat regions instead of stairs

  vector<ll> maxes = range_maxes(v, k);  // maxes[i]: max value in the i-th K length interval

  vector<ll> ps(n + 1);
  partial_sum(v.begin(), v.end(), ps.begin() + 1);

  ll best = LLONG_MAX;
  for (int i = 0; i <= n - k; i++) {
    ll sum = ps[i + k] - ps[i];  // sum of values in the i-th K length interval
    ll cost = k * maxes[i] - sum;
    best = min(best, cost);
  }
  cout << best;
}
