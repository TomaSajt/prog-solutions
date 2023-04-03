#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
int main() {
    speed;
    int n;
    cin >> n;
    while (cin >> n) {
        vector<int> a(n);
        for (int& i : a) cin >> i;
        sort(a.rbegin(), a.rend());
        cout << ((a.size() == 1 && a[0] == 1) || (a.size() > 1) && a[0] - a[1] <= 1 ? "YES" : "NO") << endl;
    }
}