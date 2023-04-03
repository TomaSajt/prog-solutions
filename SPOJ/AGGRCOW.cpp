#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

bool check(const vector<int>& stalls, int dist, int c) {
    int last = stalls[0];
    int count = 1;
    for (int s : stalls) {
        if (s - last >= dist) {
            last = s;
            if (++count >= c) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    speed;
    int n, c;
    cin >> n;
    while (cin >> n >> c) {
        vector<int> stalls(n);
        for (auto& s : stalls) cin >> s;
        sort(stalls.begin(), stalls.end());
        int curr = 0;
        for (int i = 30; i >= 0; --i) {
            int next = curr + (1 << i);
            if (check(stalls, next, c)) curr = next;
        }
        cout << curr << '\n';
    }
}