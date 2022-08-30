#include "../_helpers.hpp"

ifstream in("C:/Users/Toma/Downloads/rosalind_mend.txt");
ofstream out("C:/Users/Toma/Downloads/rosalind_mend_out.txt");

typedef array<double, 3> prob;

struct node {
    node* children[2] = { 0,0 };
    int deps = 0;
    prob probs = { -1,-1,-1 };
};

prob mate(const prob& a, const prob& b) {
    prob r = { 1, 0.5, 0 };
    prob res = { 0, 0, 0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double p = a[i] * b[j];
            res[0] += p * (r[i] * r[j]);
            res[1] += p * (r[i] + r[j] - 2 * r[i] * r[j]);
            res[2] += p * (1 - r[i] - r[j] + r[i] * r[j]);
        }
    }
    return res;
}

void build_tree(istream& in, node* par) {
    if (in.peek() == '(') {
        in.ignore(1);
        par->children[0] = new node();
        par->children[1] = new node();
        par->deps += 2;
        build_tree(in, par->children[0]);
        in.ignore(1);
        build_tree(in, par->children[1]);
        in.ignore(1);
    }
    else {
        char c1, c2;
        cin >> c1 >> c2;
        if (c2 == 'A') par->probs = { 1,0,0 };
        else if (c1 == 'a') par->probs = { 0,0,1 };
        else par->probs = { 0,1,0 };
    }
}

void compute(node* node) {
    if (node->children[0] == nullptr) return;
    compute(node->children[0]), compute(node->children[1]);
    node->probs = mate(node->children[0]->probs, node->children[1]->probs);
}

int main() {
    node root;
    build_tree(cin, &root);
    compute(&root);
    auto a = root.probs;
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
}