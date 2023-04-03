#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
bool vis[7][7];
string pat;
int res = 0;
inline bool canStep(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7 && !vis[x][y];
}

void rec(int x, int y, char prevStep, int i) {
    if (i != 0 && pat[i - 1] != '?' && pat[i - 1] != prevStep) return;
    if (x == 0 && y == 6) {
        if (i == 48) res++;
        return;
    }
    if (prevStep == 'R' && !canStep(x + 1, y) && canStep(x, y - 1) && canStep(x, y + 1)) return;
    if (prevStep == 'L' && !canStep(x - 1, y) && canStep(x, y - 1) && canStep(x, y + 1)) return;
    if (prevStep == 'D' && !canStep(x, y + 1) && canStep(x - 1, y) && canStep(x + 1, y)) return;
    if (prevStep == 'U' && !canStep(x, y - 1) && canStep(x - 1, y) && canStep(x + 1, y)) return;

    vis[x][y] = 1;
    if (canStep(x + 1, y)) rec(x + 1, y, 'R', i + 1);
    if (canStep(x - 1, y)) rec(x - 1, y, 'L', i + 1);
    if (canStep(x, y + 1)) rec(x, y + 1, 'D', i + 1);
    if (canStep(x, y - 1)) rec(x, y - 1, 'U', i + 1);
    vis[x][y] = 0;
}

int main() {
    speed;
    cin >> pat;
    rec(0, 0, 'R', 0);
    cout << res;
}