//Based on https://atrium.lib.uoguelph.ca/xmlui/bitstream/handle/10214/8812/Wong_ChiHim_201505_PhD.pdf

#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int n;

int is_necklace() {
    int i, p = 1;
    for (i = 2; i <= n; i++) {
        if (b[i - p] > b[i]) return 0;
        if (b[i - p] < b[i]) p = i;
    }
    if (n % p != 0) return 0;
    return p;
}

int g() {
    for (int i = 1; i < n; i++) b[i] = a[i + 1];
    b[n] = 1;
    if (is_necklace()) return 1;
    for (int i = 1; i <= n; i++) b[i] = a[i];
    int j = is_necklace();
    if (j > 0) return j;
    for (j = 0; j < n; j++) if (a[n - j] == 1) break;
    return n - j;
}

void DB() {
    vector<int> out;
    while (true) {
        int res = g();
        for (int i = 1; i <= res; i++) out.push_back(a[i]);
        for (int i = 1; i <= n; i++) b[i] = a[i];
        for (int i = 1; i <= n - res + 1; i++) a[i] = b[i + res - 1];
        for (int i = 1; i < res; i++) a[n - res + 1 + i] = b[i];

        for (int i = 1; i < n; i++) b[i] = a[i + 1];
        b[n] = 1;
        int fb = a[1];
        for (int i = 1; i < n; i++) a[i] = a[i + 1];
        a[n] = fb;
        if (is_necklace()) a[n] = (a[n] + 1) % 2;

        if (all_of(a.begin() + 1, a.end(), [](int u) { return u == 0; })) break;
    }
    for (int u : out) cout << u;
    for (int i = 0; i < n - 1; i++) cout << out[i];
}


int main() {
    cin >> n;
    a.assign(n + 1, 0), b.assign(n + 1, 0);
    DB();
}