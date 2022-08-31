#include "../_helpers.hpp"

map<char, char> bp = { {'A','U'}, {'U','A'}, {'C','G'}, {'G','C'} };

vector<vector<ll>> dp(300, vector<ll>(300, -1));
ll solve(const string& str, int s, int e) {
    if (s > e) return 1;
    if (dp[s][e] != -1) return dp[s][e];
    ll res = solve(str, s + 1, e);
    for (int i = s + 1; i <= e; i++) {
        if (bp[str[s]] == str[i]) {
            res += solve(str, s + 1, i - 1) * solve(str, i + 1, e);
        }
    }
    return dp[s][e] = res % 1000000;
}

int main() {
    string str = rosalind::getFasta(cin)[0].second;
    cout << solve(str, 0, str.size() - 1);
}