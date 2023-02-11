#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int n, k;
vector<int> nextSel(vector<int> v) {
    for (int ri = 0; ri < k; ri++) {
        int i = k - ri - 1;
        int expected = n - 2 * ri;
        if (v[i] != expected) {
            for (int ind = i, val = v[i] + 1; ind < k; ind++, val += 2) {
                v[ind] = val;
            }
            return v;
        }
    }
    for (int i = 0; i < k; i++) {
        v[i] = 2 * i + 1;
    }
    return v;
}

vector<int> prevSel(vector<int> v) {
    for (int ri = 0; ri < k; ri++) {
        int i = k - ri - 1;
        int expected = v.back() - 2 * ri;
        if (v[i] != expected) {
            v[i + 1]--;
            for (int ind = k - 1, val = n; ind > i + 1; ind--, val -= 2) {
                v[ind] = val;
            }
            return v;
        }

    }
    if (v[0] == 1) {
        for (int i = k - 1, val = n; i >= 0; i--, val -= 2) {
            v[i] = val;
        }
    }
    else {
        v[0]--;
        for (int i = k - 1, val = n; i > 0; i--, val -= 2) {
            v[i] = val;
        }
    }

    return v;
}


int main() {
    speed;
    cin >> n >> k;
    vector<int> v(k);
    for (auto& a : v) cin >> a;
    for (auto a : prevSel(v)) cout << a << ' ';
    cout << '\n';
    for (auto a : nextSel(v)) cout << a << ' ';
}