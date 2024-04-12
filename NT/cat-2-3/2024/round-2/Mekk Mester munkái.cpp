#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h;
  cin >> n >> h;

  vector<array<int, 3>> jobs;
  for (int i = 1; i <= n; i++) {
    int s, e;
    cin >> s >> e;
    jobs.push_back({s, e, i});
  }

  sort(jobs.begin(), jobs.end(), [](auto a, auto b) { return a[1] < b[1]; });

  int last_end_a = 0, last_end_b = 0;
  vector<int> done_job_ids_a, done_job_ids_b;
  for (auto [s, e, id] : jobs) {
    if (last_end_a < last_end_b) swap(last_end_a, last_end_b), swap(done_job_ids_a, done_job_ids_b);
    // let A be the person, who has been idle for the least time
    if (s > last_end_a) {
      last_end_a = e;
      done_job_ids_a.push_back(id);
    }
    else if (s > last_end_b) {
      last_end_b = e;
      done_job_ids_b.push_back(id);
    }
  }
  cout << done_job_ids_a.size() << ' ' << done_job_ids_b.size() << '\n';
  for (int id : done_job_ids_a) cout << id << ' ';
  cout << '\n';
  for (int id : done_job_ids_b) cout << id << ' ';
}
