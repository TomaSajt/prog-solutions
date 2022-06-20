cpp
#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int n;
string s1, s = "";

int solve(int i, int j) {

}


int main() {
    speed;
    cin >> n >> s1;
    char c = ' ';
    for (char& ch : s1) {
        if (ch != c) s += ch;
        c = ch;
    }
    n = s.size();
    cout << n << endl;
    cout << solve(0, n - 1);
}