#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), cin.sync_with_stdio(0);

  int n;
  cin >> n;

  vector<array<int, 2>> v(n);
  for (int i = 0; i < n; i++) cin >> v[i][0];
  for (int i = 0; i < n; i++) cin >> v[i][1];

  sort(v.begin(), v.end());

  int l = 0, r = n - 1;
  long long xp = 0, time = 0;
  while (l <= r) {
    // collect resource with lowest xp requirement, if it is met
    if (v[l][0] <= xp) {
      time += v[l][1];
      xp += v[l][1];
      v[l][1] = 0;
      l++;
    }
    // else collect the resource with the xp requirement that is the most unlikely to be met (the highest)
    else {
      time += 2;
      xp++;
      v[r][1]--;
      if (v[r][1] == 0) r--;
    }
  }
  cout << time;
}
