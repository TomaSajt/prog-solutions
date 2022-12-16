#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    int l = 2 * k + 1;
    int m = n + 2 * k;
    vector<int> v(m, INT_MIN);
    for (int i = k; i < n + k; i++) cin >> v[i];
    deque<int> dq;
    vector<int> res(m - l + 1);
    for (int i = 0; i < m; i++) {
        while (!dq.empty() && i - dq.front() >= l) dq.pop_front();
        while (!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();
        dq.push_back(i);
        if (i - l + 1 >= 0) res[i - l + 1] = v[dq.front()];
    }
    for (int i = 0; i < n; i++) {
        if (v[i + k] >= res[i]) {
            cout << i + 1;
            return 0;
        }
    }
    cout << "-1";
}