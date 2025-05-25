#include <bits/stdc++.h>
using namespace std;

//vector<int> sol = {4, 3, 2, 1, 5};

int ask(int pos1, int pos2) {
  /*int a = sol[pos1 - 1] & sol[pos2 - 1];
  for (int i = 31; i >= 0; i--) {
    if (((a >> i) & 1) == 1) return i;
  }
  return -1;*/
  cout << "? " << pos1 << ' ' << pos2 << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> pos_to_mag(n + 1);
  map<int, int> mag_to_pos;
  vector<bitset<10>> pos_to_sol(n + 1);
  for (int i = 1; i <= n; i++) {
    int mag = ask(i, i);
    pos_to_mag[i] = mag;
    mag_to_pos[mag] = i;
    pos_to_sol[i].set(mag);
  }
  for (int pos = 1; pos <= n; pos++) {
    int mag = pos_to_mag[pos];
    if (mag != 0) {
      for (int prev_mag = mag - 1; prev_mag >= 0; prev_mag--) {
        int prev_pos = mag_to_pos[prev_mag];
        int and_mag = ask(pos, prev_pos);
        if (and_mag == prev_mag) {
          pos_to_sol[pos].set(prev_mag);
        }
      }
    }
  }
  cout << '!';
  for (int i = 1; i <= n; i++) {
    cout << ' ' << pos_to_sol[i].to_ulong();
  }
}
