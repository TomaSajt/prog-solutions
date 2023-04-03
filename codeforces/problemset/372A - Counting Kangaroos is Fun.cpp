#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
int main() {
    speed;
    int n;
    cin >> n;
    vector<int> s(n);
    for (int& a : s) cin >> a;
    sort(s.begin(), s.end());
    int i, j, vis = s.size();
    for (i = 0, j = s.size() / 2; i < s.size() / 2 && j < s.size(); i++) {
        for (; s[i] * 2 > s[j] && j < s.size(); j++);
        if (j == s.size()) continue;
        s[j] = 0;
        vis--;
    }
    cout << vis << endl;
}