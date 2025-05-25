#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int check(int x, int y, int ax, int ay, int bx, int by) {
  return (ax - x) * (bx - x) + (ay - y) * (by - y);
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int topLeftX, topLeftY;
  cin >> topLeftX >> topLeftY;
  int topRightX, topRightY;
  cin >> topRightX >> topRightY;
  int bottomRightX, bottomRightY;
  cin >> bottomRightX >> bottomRightY;
  int bottomLeftX, bottomLeftY;
  cin >> bottomLeftX >> bottomLeftY;

  int n;
  cin >> n;
  int o = 0;
  while (n--) {
    int currX, currY;
    cin >> currX >> currY;
    int res1 = check(currX, currY, topLeftX, topLeftY, topRightX, topRightY);
    int res2 = check(currX, currY, topRightX, topRightY, bottomRightX, bottomRightY);
    int res3 = check(currX, currY, bottomRightX, bottomRightY, bottomLeftX, bottomLeftY);
    int res4 = check(currX, currY, bottomLeftX, bottomLeftY, topLeftX, topLeftY);
    int hegyes = (res1 > 0) + (res2 > 0) + (res3 > 0) + (res4 > 0);
    int tompa = (res1 < 0) + (res2 < 0) + (res3 < 0) + (res4 < 0);
    if (hegyes == 2 && tompa == 2) o++;
  }
  cout << o;
}
