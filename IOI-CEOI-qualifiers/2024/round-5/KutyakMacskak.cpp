// 69.22/1000
// ~19000 ask calls

#include "KutyakMacskak.h"
#include <bits/stdc++.h>
using namespace std;

bool is_closer(int k, int x, int y) {
  if (x == y) return 0;
  return ask(k, x, y) == x;
}

std::vector<int> find_order(int N, int M) {
  int top_cat = 1;
  for (int cat = 2; cat <= M; cat++) {
    if (is_closer(1, top_cat, cat)) {
      top_cat = cat;
    }
  }

  int top_dog = -1;
  for (int dog = 1; dog <= N; dog++) {
    bool bad = 0;
    for (int cat = 1; cat <= M; cat++) {
      if (is_closer(dog, cat, top_cat)) {
        bad = 1;
        break;
      }
    }
    if (!bad) {
      top_dog = dog;
      break;
    }
  }

  vector<int> cat_poses(M);
  iota(cat_poses.begin(), cat_poses.end(), 1);
  sort(cat_poses.begin(), cat_poses.end(), [&](int x, int y) { return is_closer(top_dog, x, y); });

  return cat_poses;
}
