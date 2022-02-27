#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> mins;
    unordered_set<int> maxes;
    int minV = 1000000000;
    int maxV = -1000000000;
    for (int i = 1; i <= n; i++) {
        int s, e;
        std::cin >> s >> e;
        if (s <= minV) {
            if (s != minV) {
                minV = s;
                mins.clear();
            }
            mins.insert(i);
        }
        if (e >= maxV) {
            if (e != maxV) {
                maxV = e;
                maxes.clear();
            }
            maxes.insert(i);
        }
    }
    for (auto max : maxes) {
        if (mins.find(max) != mins.end()) {
            cout << max << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}