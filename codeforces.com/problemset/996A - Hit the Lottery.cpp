#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int nums[] = { 100,20,10,5,1 };
int main() {
    speed;
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < 5;i++) {
        res += n / nums[i];
        n %= nums[i];
    }
    cout << res << endl;
}