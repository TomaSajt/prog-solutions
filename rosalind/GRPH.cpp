#include "_helpers.hpp"
typedef long long ll;
#include <bits/stdc++.h>

bool overlap(const string& a, const string& b, int k) {
    if (a == b) return false;
    for (int i = 0; i < k;i++) {
        if (a[a.size() + i - k] != b[i]) return false;
    }
    return true;
}


int main() {
    ifstream input("C:/Users/Toma/Downloads/rosalind_grph(2).txt");
    auto fasta = rosalind::getFasta(input);
    int n = fasta.size();
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            auto& [name1, str1] = fasta[i];
            auto& [name2, str2] = fasta[j];
            if (overlap(str1, str2, 3)) {
                cout << name1 << ' ' << name2 << endl;
            }
        }
    }
}