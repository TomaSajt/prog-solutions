// WIP

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int BS = 140;

struct query {
  int l, r, ind;

  bool operator<(query other) {
    int b = l / BS, bo = other.l / BS;
    if (b != bo) return b < bo;
    return b % 2 == 0 ? r < other.r : r > other.r;
  }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> h(n + 1);
  for (int i = 1; i <= n; i++) cin >> h[i];

  vector<query> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].ind = i;
  }

  sort(queries.begin(), queries.end());
  vector<int> sol(q);

  vector<int> len(n + 1, 0);
  vector<int> par(n + 1, -1);
  vector<int> ch_l(n + 1, -1);
  vector<int> ch_r(n + 1, -1);

  stack<int> desc_poses;
  for (int i = 1; i <= n; i++) {
    while (!desc_poses.empty() && h[desc_poses.top()] < h[i]) desc_poses.pop();
    par[i] = desc_poses.empty() ? -1 : desc_poses.top();
    desc_poses.push(i);
    if (par[i] != -1) {
      ch_l[i] = ch_r[par[i]];
      cout << "ch_l[i] = " << ch_l[i] << endl;
      if (ch_l[i] != -1) {
        par[ch_l[i]] = i;
        cout << "par[ch_l[i]] = " << i << endl;
      }
      ch_r[par[i]] = i;
      cout << "ch_r[par[i]] = " << i << endl;
    }
    for (int j = 1; j <= i; j++) {
      cout << h[j] << ' ';
    }
    cout << endl;
    for (int j = 1; j <= i; j++) {
      cout << par[j] << ' ';
    }
    cout << endl;
    cout << endl;
  }
  /*
      auto rem_r = [&](int i) {
          cout << "rem_r" << i << endl;
          par[ch_l[i]] = par[i];
          if(par[i] != -1) ch_r[par[i]] = ch_l[i];
          ch_l[i]=-1;
          par[i]=-1;
      };
      */

  for (auto [l, r, ind] : queries) {
    sol[ind] = 0;
  }

  for (int s : sol) cout << s << '\n';

  return 0;
}
