// 100/100
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> col_to_row;
vector<bool> row_occupied;
vector<bool> diag_sum_occupied;
vector<bool> diag_sub_occupied;
bool a = false;
bool backtrack(int col) {
    if (col == n) {
        for (int& i : col_to_row) cout << i + 1 << ' ';
        cout << '\n';
        a = true;
        return true;
    }
    for (int row = 0; row < n; row++) {
        int sum_diag = row + col;
        int sub_diag = col - row + n - 1;
        if (row_occupied[row] || diag_sub_occupied[sub_diag] || diag_sum_occupied[sum_diag]) continue;

        row_occupied[row] = diag_sub_occupied[sub_diag] = diag_sum_occupied[sum_diag] = true;
        col_to_row[col] = row;
        if (backtrack(col + 1)) return true;
        col_to_row[col] = -1;
        row_occupied[row] = diag_sub_occupied[sub_diag] = diag_sum_occupied[sum_diag] = false;

    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    col_to_row.resize(n, -1);
    row_occupied.resize(n, false);
    diag_sum_occupied.resize(2 * n - 1, false);
    diag_sub_occupied.resize(2 * n - 1, false);
    if (!backtrack(0)) cout << "-1\n";
}