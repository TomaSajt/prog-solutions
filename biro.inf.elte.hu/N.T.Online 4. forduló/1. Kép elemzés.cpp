#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

struct cell {
    int v, x, y;
};
struct class_data {
    int l = INT_MAX, t = INT_MAX, r = INT_MIN, b = INT_MIN, c = 0;
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<cell> cells(n * m);
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < m;j++) {
            int v;
            cin >> v;
            cells[i * m + j] = { v, j, i };
        }
    }
    sort(cells.begin(), cells.end(), [](cell& a, cell& b) {return a.v < b.v;});
    vector<class_data> a;
    for (int i = 0;i < n * m;i++) {
        bool b = false;
        if (i == 0 || (cells[i].v - cells[i - 1].v > 1)) {
            a.push_back({});
            b = true;
        }
        if (b || cells[i].v != cells[i - 1].v) {
            a.back().c++;
        }
        a.back().l = min(a.back().l, cells[i].x);
        a.back().r = max(a.back().r, cells[i].x);
        a.back().t = min(a.back().t, cells[i].y);
        a.back().b = max(a.back().b, cells[i].y);
    }
    cout << a.size() << endl;
    auto best = min_element(a.begin(), a.end(), [](class_data& a, class_data& b) {return a.c > b.c;});
    cout << best->c << endl;
    cout << best->t + 1 << ' ' << best->l + 1 << ' ' << best->b + 1 << ' ' << best->r + 1 << endl;

}