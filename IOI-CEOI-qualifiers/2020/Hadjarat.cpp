#include <bits/stdc++.h>
using namespace std;
// this solution was made using mraron's solution as a reference (on njudge)

struct point {
  int x, y, id;
  bool operator<(const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

// `best[i]` is the best endings for series of length `i`
// we always make sure that inside `best[i]`
// every `.x` is unique and is in increasing order
// every `.y` is unique and is in decreasing order
// we try to minimize `.y` as much as possible
vector<set<point>> best(1, {{-1, -1, 0}});

// Is there a series of length `k` which could be extended to using `p`
// If there is, returns the `.id` of the last element of the series
// If not, returns -1
int extends(int k, point p) {
  auto it = best[k].lower_bound({p.x, -1, -1});
  // if there are no smaller `.x` values than `p.x` it is 100% not possible
  if (it == best[k].begin())
    return -1;
  --it;
  // we know that `it->x` < `p.x`, no need to check
  if (it->y >= p.y)
    return -1;
  return it->id;
}

// what is the longest series which could be extended by `p`
// returns the length of the series and the `.id` of the last element
pair<int, int> get_longest_extension(point p) {
  int l = 0, r = best.size();
  int id = 0;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int res = extends(mid, p);
    if (res != -1) {
      l = mid;
      id = res;
    } else {
      r = mid;
    }
  }
  return {l, id};
}

// tries to insert `p` into `best[k]` while ensuring the two-way sort order
void insert_and_prune(int k, point p) {
  if (k >= best.size()) {
    best.push_back({p});
    return;
  }
  auto it = best[k].lower_bound(p);

  // if not the first in the sort order
  if (it != best[k].begin()) {
    auto p_it = std::prev(it);
    // if the two-way sorted structure would be broken, don't insert
    if (p_it->x == p.x || p_it->y == p.y)
      return;
  }
  it = best[k].insert(it, p);
  ++it;
  // ensure decreasing `.y` values
  while (it != best[k].end() && it->y >= p.y) {
    it = best[k].erase(it);
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;

  vector<int> prev(n + 1);
  for (int i = 1; i <= n; i++) {
    point p;
    cin >> p.x >> p.y;
    p.id = i;
    auto [k, pi] = get_longest_extension(p);
    prev[i] = pi;
    insert_and_prune(k + 1, p);
  }

  int curr = best.back().begin()->id;
  stack<int> res;
  while (curr != 0) {
    res.push(curr);
    curr = prev[curr];
  }
  cout << res.size() << '\n';
  while (!res.empty()) {
    cout << res.top() << ' ';
    res.pop();
  }
  return 0;
}
