#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    int res = 0;
    res += n / 100;
    n %= 100;
    res += n / 20;
    n %= 20;
    res += n / 10;
    n %= 10;
    res += n / 5;
    n %= 5;
    res += n;
    cout << res << endl;
}