#include <bits/stdc++.h>
using namespace std;

vector<int> c = {-1, 50, 30, 100, 70, 60, 40, 10, 20, 90, 80};
vector<int> a = {-1, 40, 20, 90, 70, 80, 30, 10, 100, 60, 50};

int kezdet() { return c.size() - 1; }

int proba(int cid, int aid) { return (c[cid] > a[aid]) - (c[cid] < a[aid]); };

void eredmeny(int cs[]) {
  for (int i = 0; i < c.size() - 1; i++) cout << cs[i] << ' ';
}
