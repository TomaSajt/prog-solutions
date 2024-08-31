#include <bits/stdc++.h>
using namespace std;

int mem[200001];
int pref_mem[200001];

int main() {
  for (int i = 1; i <= 200000; i++) {
    int a = i;
    while (a > 0) {
      a /= 3;
      mem[i]++;
    }
    pref_mem[i] = pref_mem[i - 1] + mem[i];
  }

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << mem[a] + pref_mem[b] - pref_mem[a - 1] << '\n';
  }
}
