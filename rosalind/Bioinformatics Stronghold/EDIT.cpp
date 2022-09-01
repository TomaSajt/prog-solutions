#include "../_helpers.hpp"

vector<vector<int>> dp(1000, vector<int>(1000, -1));

int solve(const string& a, const string& b, int i, int j) {
    if (a.size() == i) return b.size() - j;
    if (b.size() == j) return a.size() - i;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) return dp[i][j] = solve(a, b, i + 1, j + 1);
    return dp[i][j] = 1 + min({ solve(a, b, i + 1,j + 1), solve(a, b, i, j + 1), solve(a,b,i + 1,j) });
}

int main() {
    auto fasta = rosalind::getFasta(cin);
    string a = fasta[0].second, b = fasta[1].second;
    cout << solve(a, b, 0, 0);
}