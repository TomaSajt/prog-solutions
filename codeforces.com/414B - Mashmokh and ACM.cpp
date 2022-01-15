#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007;
int n, k;
vector<vector<int>> memory;
ll solve(int base, int length) {
    if (length == 1)
        return 1;
    if (memory[base][length] != -1)
        return memory[base][length];
    ll sum = 0;
    for (int i = 1; i * base <= n; i++) {
        sum += solve(i * base, length - 1);
    }
    return memory[base][length] = sum % MOD;
}

int main() {
    cin >> n >> k;

    memory = vector<vector<int>>(n + 1, vector<int>(k + 2, -1));
    cout << solve(1, k + 1) << endl;
}
