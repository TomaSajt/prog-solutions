// https://oj.uz/problem/view/CEOI20_FANCYFENCE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll solve_rect(ll h, ll w) {
  h %= mod;
  w %= mod;
  ll hc = (h * (h + 1) / 2) % mod;
  ll wc = (w * (w + 1) / 2) % mod;
  return (hc * wc) % mod;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  set<pair<ll, int>, greater<pair<ll, int>>> height_index_set;
  map<int, pair<ll, ll>> index_dim_map;

  height_index_set.insert({0, -1});
  height_index_set.insert({0, n});
  index_dim_map[-1] = {0, 0};
  index_dim_map[n] = {0, 0};

  {
    vector<ll> hv(n), wv(n);
    for (ll& h : hv) cin >> h;
    for (ll& w : wv) cin >> w;
    for (int i = 0; i < n; i++) {
      if (i != n + 1 && hv[i] == hv[i + 1]) {
        wv[i + 1] += wv[i];
        continue;
      }
      index_dim_map[i] = {hv[i], wv[i]};
      height_index_set.insert({hv[i], i});
    }
  }
  ll res = 0;

  while (height_index_set.size() > 1) {
    auto _it = height_index_set.begin();
    int ind_curr = _it->second;
    height_index_set.erase(_it);

    // should always be the iterator at key ind_curr
    auto it_curr = index_dim_map.lower_bound(ind_curr);
    auto& [h_curr, w_curr] = it_curr->second;

    auto it_next = it_curr;
    it_next++;
    auto& [h_next, w_next] = it_next->second;

    auto it_prev = it_curr;
    it_prev--;
    auto& [h_prev, w_prev] = it_prev->second;

    res += solve_rect(h_curr, w_curr);

    if (h_prev > h_next) {
      res -= solve_rect(h_prev, w_curr);
      w_prev = (w_prev + w_curr) % mod;
    }
    else if (h_prev < h_next) {
      res -= solve_rect(h_next, w_curr);
      w_next = (w_next + w_curr) % mod;
    }
    else {
      res -= solve_rect(h_prev, w_curr);
      w_prev = (w_prev + w_curr + w_next) % mod;
      height_index_set.erase({h_next, it_next->first});
      index_dim_map.erase(it_next);
    }
    res = (res % mod + mod) % mod;
    index_dim_map.erase(it_curr);
  }
  cout << res;
}
