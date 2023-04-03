#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    // elég lenne a k+1, csak valamiért nem tudnak normális teszteseteket írni
    vector<int> lastSeen(k + 2, -1), maxDist(k + 1, -1); 
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (lastSeen[a] != -1) maxDist[a] = max(maxDist[a], i - lastSeen[a]);
        lastSeen[a] = i;
    }
    int sol = -1;
    for (int i = 1; i <= k; i++) {
        if (maxDist[i] == -1) continue;
        if (sol == -1 || maxDist[sol] > maxDist[i]) sol = i;
    }
    cout << sol;
}