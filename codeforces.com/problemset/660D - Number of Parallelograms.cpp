#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef pair<int, int> v2d;

int main() {
    speed;
    int n;
    cin >> n;
    vector<v2d> points(n);
    for (auto& p : points)cin >> p.first >> p.second;
    map<v2d, int> diffs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1;j < n;j++) {
            v2d& p1 = points[i], p2 = points[j];
            v2d diff = { p1.first - p2.first,p1.second - p2.second };
            if (diff.second > 0 || (diff.second == 0 && diff.first > 0)) {
                diff.second *= -1;
                diff.first *= -1;
            }
            diffs[diff]++;
        }
    }
    int sum = 0;
    for (auto& [diff, count] : diffs) {
        sum += count * (count - 1) / 2;
    }
    cout << sum / 2;
}