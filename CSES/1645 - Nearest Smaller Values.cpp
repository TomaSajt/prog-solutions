#include <bits/stdc++.h>
using namespace std;

// fenwick tree
int ft[200001];

int get(int pos) {
  int res = 0;
  for (; pos > 0; pos -= (pos & -pos)) res = max(res, ft[pos]);
  return res;
}

// the value has to be greater then it was previously, otherwise this is invalid
void update(int pos, int val) {
  for (; pos <= 200000; pos += (pos & -pos)) ft[pos] = max(ft[pos], val);
}

int main() {
  int n;
  cin >> n;

  vector<int> x(n + 1);
  set<int> nums;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    nums.insert(x[i]);
  };
  map<int, int> compressor;
  int c = 1;
  for (int num : nums) compressor[num] = c++;
  for (int i = 1; i <= n; i++) x[i] = compressor[x[i]];
  for (int i = 1; i <= n; i++) {
    cout << get(x[i] - 1) << ' ';
    update(x[i], i);
  }
}
