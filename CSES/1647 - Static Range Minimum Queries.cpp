#include <bits/stdc++.h>
using namespace std;

template <typename T> class sparse_table {
  vector<vector<T>> table;
  function<T(T, T)> op;

public:
  sparse_table(const vector<T> &vec, function<T(T, T)> op)
      : table(log2l(vec.size()) + 1, vector<T>(vec.size())), op(op) {
    table[0] = vec;
    int n = table[0].size();
    int l = table.size();
    for (int i = 1; i < l; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  int get_o1(int l, int r) {
    int i = log2l(r - l);
    return op(table[i][l], table[i][r - (1 << i)]);
  }
};

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<int> vec(n);
  for (auto &x : vec)
    cin >> x;

  sparse_table<int> st(vec, [](int a, int b) { return min(a, b); });

  while (q--) {
    int a, b;
    cin >> a;
    cin >> b;
    cout << st.get_o1(a - 1, b) << '\n';
  }
}
