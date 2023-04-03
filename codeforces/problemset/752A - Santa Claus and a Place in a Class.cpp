#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k; k--;
    int col = k / (2 * m);
    int posInCol = k % (2 * m);
    int row = posInCol / 2;
    int side = posInCol % 2;
    cout << col + 1 << ' ' << row + 1 << ' ' << "LR"[side];
}