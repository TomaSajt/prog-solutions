#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// a special rb-tree which can get the index of certain elements
template <class T>
using itree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
    
  // the second part is just for uniqueness
  itree<array<int, 2>> tr;

  vector<int> salaries(n);
  for (int i = 0; i < n; i++) {
    cin >> salaries[i];
    tr.insert({salaries[i], i});
  }

  while (q--) {
    char o;
    int u, v;
    cin >> o >> u >> v;
    if (o == '!') {
      u--;
      tr.erase({salaries[u], u});
      tr.insert({v, u});
      salaries[u] = v;
    } else {
      cout << tr.order_of_key({v, INT_MAX}) - tr.order_of_key({u, -1}) << '\n';
    }
  }
}
