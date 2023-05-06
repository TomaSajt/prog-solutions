#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto& a : vec) cin >> a;
    vector<int> r1(n - k + 1);
    deque<int> dq1, dq2;
    for (int i = 0; i < n; i++) {
        while (!dq1.empty() && i - dq1.front() >= k) dq1.pop_front();
        while (!dq1.empty() && vec[dq1.back()] >= vec[i]) dq1.pop_back();
        dq1.push_back(i);

        while (!dq2.empty() && i - dq2.front() >= k) dq2.pop_front();
        while (!dq2.empty() && vec[dq2.back()] <= vec[i]) dq2.pop_back();
        dq2.push_back(i);

        if (i >= k - 1) {
            r1[i - k + 1] = vec[dq2.front()] - vec[dq1.front()];
        }
    }
    auto mi = min_element(r1.begin(), r1.end());
    cout << *mi << '\n' << mi - r1.begin() + 1;
}