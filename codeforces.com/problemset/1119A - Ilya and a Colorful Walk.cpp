#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
int main() {
    speed;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;
    int r1 = find_if(v.begin(), v.end(), [&](int a) {return a != v[n - 1];}) - v.begin();
    int r2 = find_if(v.rbegin(), v.rend(), [&](int a) {return a != v[0];}) - v.rbegin();
    cout << n - min(r1, r2) - 1 << endl;

}