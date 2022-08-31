#include "../_helpers.hpp"
#include "../BigInt.hpp"

bool can_connect(char c1, char c2) {
    if (c1 > c2) swap(c1, c2);
    return c1 == 'A' && c2 == 'U' || c1 == 'C' && c2 == 'G' || c1 == 'G' && c2 == 'U';
}
vector<vector<BigInt>> dp(200, vector<BigInt>(200, -1));
BigInt solve(const string& str, int s, int e) {
    if (s > e) return 1;
    if (dp[s][e] != -1) return dp[s][e];
    BigInt res = solve(str, s + 1, e);
    for (int i = s + 4; i <= e; i++) {
        if (can_connect(str[s], str[i])) {
            res += solve(str, s + 1, i - 1) * solve(str, i + 1, e);
        }
    }
    return dp[s][e] = res;
}

int main() {
    string str;
    cin >> str;
    cout << solve(str, 0, str.size() - 1);
}