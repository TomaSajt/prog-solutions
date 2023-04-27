#include <bits/stdc++.h>
using namespace std;

const int block_size = 170;

struct query {
  int l, r, ind;
  bool operator<(const query &other) {
    return make_pair(l / block_size, r) <
           make_pair(other.l / block_size, other.r);
  }
};

int main() {

  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> vals(n);
  for (int &a : vals)
    cin >> a;

  int q;
  cin >> q;
  vector<query> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].l--;
    queries[i].r--;
    queries[i].ind = i;
  }
  sort(queries.begin(), queries.end());

  vector<int> counts(1e6 + 1);
  int curr_ans = 0;
  vector<int> answers(q);
  int l = 0, r = -1;
  for (auto &q : queries) {
    while (q.l < l) {
      l--;
      curr_ans += !counts[vals[l]];
      counts[vals[l]]++;
    }
    while (q.l > l) {
      counts[vals[l]]--;
      curr_ans -= !counts[vals[l]];
      l++;
    }
    while (q.r < r) {
      counts[vals[r]]--;
      curr_ans -= !counts[vals[r]];
      r--;
    }
    while (q.r > r) {
      r++;
      curr_ans += !counts[vals[r]];
      counts[vals[r]]++;
    }
    answers[q.ind] = curr_ans;
  }
  for (int &a : answers)
    cout << a << '\n';
}
