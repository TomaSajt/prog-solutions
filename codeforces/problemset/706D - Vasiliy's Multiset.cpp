#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int dig(int a, int i) { return (a >> (30 - i)) & 1; }
struct Node {
    Node* next[2] = { 0 };
    int passthroughCount = 0;
    int value = -1;

    void add(int val, int pos = 0) {
        passthroughCount++;
        if (pos == 31) {
            value = val;
            return;
        }
        int b = dig(val, pos);
        if (next[b] == nullptr) next[b] = new Node;
        next[b]->add(val, pos + 1);
    }

    void remove(int val, int pos = 0) {
        passthroughCount--;
        if (pos == 31) return;
        int b = dig(val, pos);
        next[b]->remove(val, pos + 1);
        if (next[b]->passthroughCount == 0) {
            delete next[b];
            next[b] = nullptr;
        }
    }

    int xor_max(int val, int pos = 0) {
        if (pos == 31) return val ^ value;
        int b = dig(val, pos);
        Node* nex = next[1 - b];
        if (nex == nullptr) {
            nex = next[b];
            if (nex == nullptr) cerr << "this shouldn't happen" << endl;
        }
        return nex->xor_max(val, pos + 1);
    }
};

int main() {
    speed;
    int n;
    cin >> n;
    Node root;
    root.add(0);
    while (n--) {
        char o; int a; cin >> o >> a;
        if (o == '+') root.add(a);
        else if (o == '-') root.remove(a);
        else cout << root.xor_max(a) << '\n';
    }
}