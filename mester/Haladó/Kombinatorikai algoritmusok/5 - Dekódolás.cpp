// 60/100 TIME LIMIT

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using itree = tree<T, null_type, greater<T>, rb_tree_tag,
                   tree_order_statistics_node_update>;

int a[100001];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  stack<int> b;
  itree<int> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    t.insert(i);
  }
  for (int i = n; i > 0; i--) {
    auto it = t.find_by_order(a[i]);
    b.push(*it);
    t.erase(it);
  }
  while (!b.empty()) {
    cout << b.top() << ' ';
    b.pop();
  }
}
