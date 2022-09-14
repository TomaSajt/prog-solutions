#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    set<int> s;
    while (cin >> n) s.insert(n);
    cout << s.size();
}