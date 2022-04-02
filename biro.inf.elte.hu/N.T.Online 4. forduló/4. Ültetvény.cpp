#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;


int m, n, k;
int s = 1, e = 1;
vector<int> basket;
vector<int> vals;
int en_c = 0;
bool has_enough() {
    return en_c == n;
}
void add(int i) {
    basket[i]++;
    if (basket[i] == k) en_c++;
}
void rem(int i) {
    basket[i]--;
    if (basket[i] == k - 1) en_c--;
}
void shrink() {
    rem(vals[s]);
    s++;
}
void expand() {
    e++;
    add(vals[e]);
}

int main() {
    speed;
    cin >> m >> n >> k;
    basket.resize(n + 1);
    vals.resize(m + 1);
    for (int i = 1;i <= m;i++) cin >> vals[i];
    add(vals[1]);
    int best = INT_MAX;
    while (e <= m) {
        if (has_enough()) {
            shrink();
        }
        else {
            expand();
        }
        if (has_enough()) {
            best = min(best, e - s + 1);
        }
    }
    cout << (best == INT_MAX ? 0 : best) << endl;
}