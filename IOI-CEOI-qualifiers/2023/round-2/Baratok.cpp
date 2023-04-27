#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template <class T>
using itree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct person {
  int pos, range;
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<person> people(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    people[i] = {i, a};
  }
  sort(people.begin(), people.end(),
       [](person a, person b) { return a.range > b.range; });
  itree<int> positions;
  ll cnt = 0;
  for (person &p : people) {
    cnt += positions.order_of_key(p.pos + p.range + 1) -
           positions.order_of_key(p.pos - p.range);
    positions.insert(p.pos);
  }
  cout << cnt;
  return 0;
}
