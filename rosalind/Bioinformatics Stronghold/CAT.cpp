#include "../_helpers.hpp"

bool can_connect(char c1, char c2) {
    return
        (c1 == 'A' && c2 == 'U') ||
        (c1 == 'U' && c2 == 'A') ||
        (c1 == 'C' && c2 == 'G') ||
        (c1 == 'G' && c2 == 'C');
}
vector<vector<ll>> dp(300, vector<ll>(300, -1));
ll solve(const string& str, int s, int e) {
    if (s == e) return 0;
    if (e < s) return 1;
    if (dp[s][e] != -1) return dp[s][e];
    ll res = 0;
    for (int i = s + 1; i <= e; i++) {
        if (can_connect(str[s], str[i])) {
            res += solve(str, s + 1, i - 1) * solve(str, i + 1, e);
        }
    }
    return dp[s][e] = res % 1000000;
}

int main() {
    ifstream in("C:/Users/Toma/Downloads/rosalind_kmp(4).txt");
    ofstream out("C:/Users/Toma/Desktop/out_kmp.txt");
    string str = rosalind::getFasta(cin)[0].second;
    int n = str.size();
    cout << solve(str, 0, n - 1);
}