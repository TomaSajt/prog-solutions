#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int GROUP_SIZE = 450;

struct query {
  int l, r, ind;
};

int main() {
  int n, t;
  cin >> n >> t;

  vector<ll> vals(n + 1);
  for (int i = 1; i <= n; i++) cin >> vals[i];

  vector<query> queries(t);
  for (int i = 0; i < t; i++) {
    queries[i].ind = i;
    cin >> queries[i].l >> queries[i].r;
  }

  auto cmp = [](query& a, query& b) {
    int ga = a.l / GROUP_SIZE, gb = b.l / GROUP_SIZE;
    if (ga != gb) return ga < gb;
    return (ga % 2 == 0) ? (a.r < b.r) : (a.r > b.r);
  };

  sort(queries.begin(), queries.end(), cmp);

  ll curr_ans = 0;
  vector<ll> val_cnt(1000001);

  auto incl = [&](ll v) {
    curr_ans -= v * val_cnt[v] * val_cnt[v];
    val_cnt[v]++;
    curr_ans += v * val_cnt[v] * val_cnt[v];
  };

  auto excl = [&](ll v) {
    curr_ans -= v * val_cnt[v] * val_cnt[v];
    val_cnt[v]--;
    curr_ans += v * val_cnt[v] * val_cnt[v];
  };

  int l = 1, r = 0;
  vector<ll> ans(t);

  for (query& q : queries) {
    while (r < q.r) {
      r++;
      incl(vals[r]);
    }
    while (q.l < l) {
      l--;
      incl(vals[l]);
    }
    while (q.r < r) {
      excl(vals[r]);
      r--;
    }
    while (l < q.l) {
      excl(vals[l]);
      l++;
    }
    ans[q.ind] = curr_ans;
  }

  for (ll an : ans) cout << an << '\n';
}
