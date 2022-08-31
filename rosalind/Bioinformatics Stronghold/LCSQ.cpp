#include "../_helpers.hpp"

int main() {
    ifstream in("C:/Users/Toma/Downloads/rosalind_lcsq.txt");
    ofstream out("C:/Users/Toma/Desktop/out_lcsq.txt");
    auto fasta = rosalind::getFasta(in);
    string a = fasta[0].second, b = fasta[1].second;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = a[i - 1] == b[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    stack<char> s;
    for (int i = n, j = m; i > 0 && j > 0;) {
        if (a[i - 1] == b[j - 1]) i--, j--, s.push(a[i]);
        else if (dp[i][j] == dp[i - 1][j]) i--;
        else j--;
    }
    while (!s.empty()) {
        out << s.top();
        s.pop();
    }
}