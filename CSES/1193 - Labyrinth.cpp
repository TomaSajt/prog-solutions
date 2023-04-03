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
    int s, e;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j <= m - 2; j++) {
            int p = m * i + j;
            char c; cin >> c;
            board[p] = c != '#';
            if (c == 'A') s = p;
            if (c == 'B') e = p;
        }
    }
    queue<int> q;
    q.push(s);
    prev[s] = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == e) break;
        vector<int> nl = { u + 1,u - 1,u + m,u - m };
        for (int v : nl) {
            if (!board[v] || prev[v]) continue;
            prev[v] = u;
            q.push(v);
        }
    }
    if (!prev[e]) {
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