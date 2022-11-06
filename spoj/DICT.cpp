#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct Node {
    int word_id = -1;
    Node* next[26] = { nullptr };
};

vector<string> words;

int chtoi(char ch) { return ch - 'a'; }

void insert(Node* node, int word_id, int ind) {
    auto& str = words[word_id];
    if (ind == str.size()) {
        node->word_id = word_id;
        return;
    }
    auto& next = node->next[chtoi(str[ind])];
    if (next == nullptr) next = new Node;
    insert(next, word_id, ind + 1);
}

void disp_all(Node* node) {
    if (node == nullptr) return;
    if (node->word_id != -1) cout << words[node->word_id] << '\n';
    for (auto next : node->next) disp_all(next);
}


bool find_disp(Node* node, const string& str, int ind) {
    if (node == nullptr) {
        cout << "No match." << '\n';
        return;
    }
    if (ind == str.size()) {
        for (int i = 0; i < 26; i++) disp_all(node->next[i]);
        return;
    }
    return find_disp(node->next[chtoi(str[ind])], str, ind + 1);
}

int main() {
    speed;
    int n;
    cin >> n;
    words.resize(n);
    Node root;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        insert(&root, i, 0);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        cout << "Case #" << i << ":\n";
        find_disp(&root, s, 0);
    }
}