// 100/100
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> col_to_row;
vector<bool> row_occupied;

void backtrack(int col) {
    if (col == n) {
        for (int& i : col_to_row) cout << i + 1 << ' ';
        cout << '\n';
        return;
    }
    for (int row = 0; row < n; row++) {
        if (row_occupied[row]) continue;
        row_occupied[row] = true;
        col_to_row[col] = row;
        backtrack(col + 1);
        col_to_row[col] = -1;
        row_occupied[row] = false;

    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    row_occupied.resize(n);
    col_to_row.resize(n, -1);
    backtrack(0);
}




/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    do {
        for (int& i : v) cout << i << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
}
*/