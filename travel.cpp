#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> vals(n);
    for (auto& i : vals) cin >> i;
    int p = 0;
    map<int, int> lastVisited;
    int best = 0;
    while (true) {
        lastVisited.clear();
        int count = 0;
        while (p < n) {
            int curr = vals[p];
            if (lastVisited.find(curr) != lastVisited.end()) {
                break;
            }
            lastVisited[curr] = p;
            count++;
            p++;
        }
        if (count > best) best = count;
        if (p >= n) break;
        p = lastVisited[vals[p]] + 1;
    }
    cout << best;

}