#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> board;
vector<vector<int>> sizeIndices;
vector<int> sizes;
int w, h, n;

bool canStep(int x, int y) {
    return x >= 0 && x < w&& y >= 0 && y < h&& board[x][y] && sizeIndices[x][y] == -1;
}
int test_pos(int x, int y) {
    if (!board[x][y])
        return 0;
    if (sizeIndices[x][y] != -1)
        return sizes[sizeIndices[x][y]];
    int sizeIndex = sizes.size();
    int res = 1;
    queue<pair<int, int>> q;
    sizeIndices[x][y] = sizeIndex;
    q.push({ x, y });
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        vector<pair<int, int>> neis = {
            {cx + 1, cy}, {cx - 1, cy}, {cx, cy + 1}, {cx, cy - 1} };
        for (auto nei : neis) {
            int nx = nei.first, ny = nei.second;
            if (canStep(nx, ny)) {
                sizeIndices[nx][ny] = sizeIndex;
                q.push({ nx, ny });
                res++;
            }
        }
    }
    sizes.push_back(res);
    return res;
}

int main() {
    cin >> w; cin.ignore();
    cin >> h; cin.ignore();
    board = vector<vector<bool>>(w, vector<bool>(h));
    sizeIndices = vector<vector<int>>(w, vector<int>(h, -1));
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < w; j++) {
            board[j][i] = line[j] == 'O';
        }
    }


    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y; cin.ignore();
        cout << test_pos(x, y) << flush << endl;
    }
}