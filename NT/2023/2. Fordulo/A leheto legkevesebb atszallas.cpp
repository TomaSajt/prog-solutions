#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

struct line {
    int s, e, id;
};

int main() {
    speed;
    int n, m; cin >> n >> m;
    vector<line> lines(n);
    for (int j = 0; j < n; j++) {
        cin >> lines[j].s >> lines[j].e;
        lines[j].id = j + 1;
    }
    int loc = 1;
    int i = 0;
    vector<int> sol;
    while (loc < m && i < n) {
        int bestI = -1;
        while (i < n && lines[i].s <= loc) {
            int bestE = bestI == -1 ? -1 : lines[bestI].e;
            if (lines[i].e > bestE) bestI = i;
            i++;
        }
        if (bestI == -1) break;
        loc = lines[bestI].e;
        sol.push_back(lines[bestI].id);
    }
    if (loc != m) {
        cout << "-1";
    }
    else {
        cout << sol.size() - 1 << '\n';
        for (auto j : sol) cout << j << ' ';
    }
    return 0;
}
