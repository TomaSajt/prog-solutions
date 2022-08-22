#include "../_helpers.hpp"

ifstream in("C:/Users/Toma/Downloads/rosalind_lgis.txt");
ofstream out("C:/Users/Toma/Downloads/rosalind_lgis_out.txt");

void solve(const vector<int>& vec, function<bool(int, int)> comp) {
    int n = vec.size();
    vector<int> dp(n, 1), prev(n);
    int bestI = 0;
    for (int i = 0; i < n; i++) {
        prev[i] = i;
        for (int j = 0; j < i; j++) {
            if (comp(vec[i], vec[j])) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if (dp[i] > dp[bestI]) {
            bestI = i;
        }
    }
    vector<int> sol = { vec[bestI] };
    int ind = bestI;
    while (prev[ind] != ind) {
        ind = prev[ind];
        sol.push_back(vec[ind]);
    }
    reverse(sol.begin(), sol.end());
    out << sol;
}

int main() {
    int n;
    in >> n;
    vector<int> vec(n);
    for (auto& i : vec) in >> i;
    solve(vec, [](int a, int b) {return a > b;});
    solve(vec, [](int a, int b) {return a < b;});
}