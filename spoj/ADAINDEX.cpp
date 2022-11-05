#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct Node {
    int cnt = 0;
    Node* next[26] = { nullptr };
};

int chtoi(char ch) { return ch - 'a'; }

void insert(Node* node, const string& str, int ind) {
    node->cnt++;
    if (ind == str.size()) return;
    auto& next = node->next[chtoi(str[ind])];
    if (next == nullptr) next = new Node;
    insert(next, str, ind + 1);
}

int get_cnt(Node* node, const string& str, int ind) {
    if (node == nullptr) return 0;
    if (ind == str.size()) return node->cnt;
    return get_cnt(node->next[chtoi(str[ind])], str, ind + 1);
}


int main() {
    speed;
    int n, q;
    cin >> n >> q;
    string s;
    Node root;
    while (n--) {
        cin >> s;
        insert(&root, s, 0);
    }
    while (q--) {
        cin >> s;
        cout << get_cnt(&root, s, 0) << '\n';
    }
}