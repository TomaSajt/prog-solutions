#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> board;
int n;

int main() {
    ifstream f(".input.txt");
    string l;
    while (f >> l) {
        board.push_back(vector<int>(l.size()));
        for (int i = 0; i < l.size(); i++) {
            board[board.size() - 1][i] = l[i] - '0';
        }
    }
    f.close();
    n = board.size();

    //find shortest path cost with dijkstra on the board from top left to bottom right
    vector<vector<int>> dist(5 * n, vector<int>(5 * n, INT_MAX / 2));
    dist[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0,{0, 0} });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int x = cur.second.first;
        int y = cur.second.second;
        cout << x << " " << y << endl;
        if (x == 5 * n - 1 && y == 5 * n - 1) {
            cout << dist[x][y] << endl;
            return 0;
        }
        if (x + 1 < n && dist[x + 1][y] > dist[x][y] + board[x + 1][y]) {
            dist[x + 1][y] = dist[x][y] + board[x + 1][y];
            pq.push({ dist[x + 1][y], { x + 1, y } });
        }
        if (y + 1 < n && dist[x][y + 1] > dist[x][y] + board[x][y + 1]) {
            dist[x][y + 1] = dist[x][y] + board[x][y + 1];
            pq.push({ dist[x][y + 1], { x, y + 1 } });
        }
        if (x - 1 >= 0 && dist[x - 1][y] > dist[x][y] + board[x - 1][y]) {
            dist[x - 1][y] = dist[x][y] + board[x - 1][y];
            pq.push({ dist[x - 1][y], { x - 1, y } });
        }
        if (y - 1 >= 0 && dist[x][y - 1] > dist[x][y] + board[x][y - 1]) {
            dist[x][y - 1] = dist[x][y] + board[x][y - 1];
            pq.push({ dist[x][y - 1], { x, y - 1 } });
        }
    }
}