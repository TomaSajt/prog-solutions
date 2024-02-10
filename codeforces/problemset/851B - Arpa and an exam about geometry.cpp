#include <bits/stdc++.h>
using namespace std;

int main() {
  long long ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if ((ax - bx) * (ax - bx) + (ay - by) * (ay - by) != (cx - bx) * (cx - bx) + (cy - by) * (cy - by) || (ax - cx) * (by - cy) == (ay - cy) * (bx - cx)) cout << "NO";
  else cout << "YES";
}
