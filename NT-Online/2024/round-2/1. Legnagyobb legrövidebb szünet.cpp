#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> last_work(n + 1, -1);
  vector<int> worst_breaks(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    if (last_work[a] != -1) {
      int l = i - last_work[a] - 1;
      if (worst_breaks[a] == -1 || worst_breaks[a] > l) {
        worst_breaks[a] = l;
      }
    }
    last_work[a] = i;
  }
  cout << max_element(worst_breaks.begin(), worst_breaks.end()) - worst_breaks.begin();
}
