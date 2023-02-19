#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    char c;
    set<char> s;
    while (cin >> c) s.insert(c);
    cout << (s.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
}