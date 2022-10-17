#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
int main() {
    speed;
    int n, m;
    cin >> n >> m;
    n += 2;
    m += 2;
    vector<bool> board(n * m);
    vector<int> prev(n * m);
    vector<int> monster_dist(n * m, -1);
    vector<int> dist(n * m, -1);
    queue<int> mq;
    int s;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j <= m - 2; j++) {
            int p = m * i + j;
            char c; cin >> c;
            board[p] = c != '#';
            if (c == 'A') s = p;
            if (c == 'M') {
                mq.push(p);
                monster_dist[p] = 0;
            }
        }
    }


    while (!mq.empty()) {
        int u = mq.front(); mq.pop();
        vector<int> nl = { u + 1,u - 1,u + m,u - m };
        for (int v : nl) {
            if (!board[v] || monster_dist[v] != -1) continue;
            monster_dist[v] = monster_dist[u] + 1;
            mq.push(v);
        }
    }

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    int e = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if ((u / m == n - 2) || (u / m == 1) || (u % m == 1) || (u % m == m - 2)) {
            e = u;
            break;
        }
        vector<int> nl = { u + 1,u - 1,u + m,u - m };
        for (int v : nl) {
            int d = dist[u] + 1;
            if (!board[v] || dist[v] != -1 || (monster_dist[v] != -1 && monster_dist[v] <= d)) continue;
            prev[v] = u;
            dist[v] = d;
            q.push(v);
        }
    }
    if (e == -1) {
        cout << "NO";
        return 0;
    }
    stack<char> st;
    int cr = e;
    while (cr != s) {
        int pr = prev[cr];
        if (pr / m < cr / m) st.push('D');
        if (pr / m > cr / m) st.push('U');
        if (pr % m < cr % m) st.push('R');
        if (pr % m > cr % m) st.push('L');
        cr = pr;
    }
    cout << "YES" << '\n' << st.size() << '\n';
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}