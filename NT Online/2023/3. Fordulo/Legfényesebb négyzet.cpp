#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int n, m, k;
vector<int> range_mins_1d(vector<int>& data) {
    deque<int> dq;
    vector<int> min_vals;
    for (int i = 0; i < data.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && data[dq.back()] > data[i]) dq.pop_back();
        dq.emplace_back(i);
        if (i >= k - 1) min_vals.emplace_back(data[dq.front()]);
    }
    return min_vals;
}

vector<vector<int>> min_ranges_2d(vector<vector<int>>& mat) {

    vector<vector<int>> row_range_minsS;
    for (auto& row : mat) {
        row_range_minsS.emplace_back(range_mins_1d(row));
    }

    vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
    for (int j = 0; j < m - k + 1; j++) {
        vector<int> col;
        for (int i = 0; i < n; i++) col.emplace_back(row_range_minsS[i][j]);

        auto col_min_ranges = range_mins_1d(col);

        for (int i = 0; i < n - k + 1; i++) {
            ans[i][j] = col_min_ranges[i];
        }
    }
    return ans;
}


int main() {
    speed;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto& row : mat) for (auto& a : row) cin >> a;

    auto ans = min_ranges_2d(mat);

    int best = INT_MIN;
    int bestI, bestJ;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < m - k + 1; j++) {
            if (ans[i][j] > best) {
                best = ans[i][j];
                bestI = i;
                bestJ = j;
            }
        }
    }
    cout << bestI + 1 << ' ' << bestJ + 1;
}