#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k, l;
    map<string, int> a, b;
    cin >> n;
    while (n--) {
        string s; int c;
        cin >> s >> c;
        a[s] += c;
    }
    cin >> n;
    while (n--) {
        string s; int c;
        cin >> s >> c;
        b[s] += c;
    }
    cin >> k >> l;
    for (auto& [s, c] : a) {
        if (c >= k && b.count(s) && b[s] >= k) cout << s << ' ';
    }
    cout << '\n';
    for (auto& [s, c] : a) {
        if (c >= l && !b.count(s)) cout << s << ' ';
    }
    cout << '\n';
    for (auto& [s, c] : b) {
        if (c >= l && !a.count(s)) cout << s << ' ';
    }
    cout << '\n';
}