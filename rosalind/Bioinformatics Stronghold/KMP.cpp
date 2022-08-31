#include "../_helpers.hpp"

int main() {
    ifstream in("C:/Users/Toma/Downloads/rosalind_kmp(2).txt");
    ofstream out("C:/Users/Toma/Desktop/out_kmp.txt");
    string str = rosalind::getFasta(in)[0].second;
    int n = str.size();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j != 0 && str[i] != str[j]) j = lps[j - 1];
        if (str[i] == str[j]) j++;
        lps[i] = j;
    }
    out << lps;
}