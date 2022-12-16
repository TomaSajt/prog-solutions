#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int lsb(int i) {
    return i & -i;
}

struct bittree {
    int size;
    vector<int> sumS;
    bittree(int size) : size(size), sumS(size + 1) {}
    int get(int i) {
        int sum = 0;
        while (i != 0) {
            sum += sumS[i];
            i -= lsb(i);
        }
    }
    int inc(int i, int v) {
        while (i <= size) {
            sumS[i] += v;
            i += lsb(i);
        }
    }
};
int main() {
    speed;
    int n;
    cin >> n;

}