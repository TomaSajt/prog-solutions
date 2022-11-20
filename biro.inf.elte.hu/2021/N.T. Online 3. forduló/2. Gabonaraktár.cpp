#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(int n) {
    speed;
    cin >> n;
    vector<pair<int, int>> data(n);
    vector<int> both(n), right(n);
    for (auto& p : data) cin >> p.first >> p.second;
    int amount = data[0].second;
    for (int i = 1; i < n; i++) {
        both[i] = amount * data[i].first + both[i - 1];
        amount += data[i].second;
    }
    amount = 0;
    for (int i = n - 2; i >= 0; i--) {
        amount += data[i + 1].second;
        right[i] = amount * data[i + 1].first + right[i + 1];
    }
    for (int i = 0; i < n; i++) both[i] += right[i];
    auto m = min_element(both.begin(), both.end());
    cout << *m << endl << distance(both.begin(), m) + 1 << endl;
}
/*#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
int main() {
    speed;
    int n, accPos = 0;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0, a, w; i < n; i++) {
        cin >> a >> w;
        accPos += a;
        arr.push_back({ accPos,w });
    }
    int min = INT_MAX;
    int minI = -1;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) s += abs(arr[i].first - arr[j].first) * arr[j].second;
        if (s < min) min = s, minI = i;
    }
    cout << min << endl << minI + 1 << endl;
}
*/