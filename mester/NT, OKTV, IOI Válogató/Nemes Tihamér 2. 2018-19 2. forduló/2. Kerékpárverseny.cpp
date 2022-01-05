#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    speed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>>
        board(n, vector<int>(m)),
        dist(n, vector<int>(m)),
        parentDir(n, vector<int>(m));
    //Tábla beolvasása
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int mI = 0, mJ = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < m; j++) {
            //Ha nem a peremen vagyunk, és a különbség kisebb mint k, és, ha a szomszéd+1 nagyobb mint a mostani érték
            if (i > 0 && abs(board[i - 1][j] - board[i][j]) <= k && dist[i - 1][j] + 1 > dist[i][j]) {
                dist[i][j] = dist[i - 1][j] + 1;
                //Az 1 tetszőleges, a bal irányt jelenti
                parentDir[i][j] = 1;
            }
            //ugyanaz mint előbb, csak másik tengelyen
            if (j > 0 && abs(board[i][j - 1] - board[i][j]) <= k && dist[i][j - 1] + 1 > dist[i][j]) {
                dist[i][j] = dist[i][j - 1] + 1;
                parentDir[i][j] = 2;
            }
            //Ha a jelenlegi hossz jobb mint a max, frissítsük a maxot
            if (dist[i][j] > dist[mI][mJ]) {
                mI = i, mJ = j;
            }
        }
    }
    //kiírja a max hosszt
    cout << dist[mI][mJ] << endl;
    stack<bool> s;
    //a stackbe beleteszi a visszakövetett irányokat boolként, mert miért is ne boolként
    while (parentDir[mI][mJ]) {
        if (parentDir[mI][mJ] == 1) {
            mI--;
            s.push(true);
        }
        else if (parentDir[mI][mJ] == 2) {
            mJ--;
            s.push(false);
        }
    }
    //mostmár az mI,mJ a kezdőkoordináta, kiírjuk 1 indexeléssel
    cout << mI + 1 << " " << mJ + 1 << endl;
    //kiírjuk a stacket, ezzel megfordítva az irányok sorrendjét
    while (!s.empty()) {
        cout << (s.top() ? "L" : "J");
        s.pop();
    }



}