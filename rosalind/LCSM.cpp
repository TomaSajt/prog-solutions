#include "_helpers.hpp"

inline bool leq(int a1, int a2, int b1, int b2) { // lexic. order for pairs
    return(a1 < b1 || a1 == b1 && a2 <= b2);
}                                                   // and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(const vector<int>& a, vector<int>& b, const vector<int>& r, int r_offset, int n, int K) { // count occurrences
    vector<int> c(K + 1, 0);
    for (int i = 0; i < n; i++) c[r[a[i] + r_offset]]++;    // count occurences
    for (int i = 0, sum = 0; i <= K; i++) { // exclusive prefix sums
        int t = c[i];  c[i] = sum;  sum += t;
    }
    for (int i = 0; i < n; i++) b[c[r[a[i] + r_offset]]++] = a[i];      // sort
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(vector<int>& s, vector<int>& SA, int n, int K) {
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    vector<int> s12(n02 + 3, 0), SA12(n02 + 3, 0), s0(n0), SA0(n0);

    // generate positions of mod 1 and mod  2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i = 0, j = 0; i < n + (n0 - n1); i++) if (i % 3 != 0) s12[j++] = i;

    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12, SA12, s, 2, n02, K);
    radixPass(SA12, s12, s, 1, n02, K);
    radixPass(s12, SA12, s, 0, n02, K);

    // find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
            name++;  c0 = s[SA12[i]];  c1 = s[SA12[i] + 1];  c2 = s[SA12[i] + 2];
        }
        if (SA12[i] % 3 == 1) { s12[SA12[i] / 3] = name; } // left half
        else { s12[SA12[i] / 3 + n0] = name; } // right half
    }

    // recurse if names are not yet unique
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array 
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    }
    else // generate the suffix array of s12 directly
        for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;

    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
    radixPass(s0, SA0, s, 0, n0, K);

    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GetI(); // pos of current offset 12 suffix
        int j = SA0[p]; // pos of current offset 0  suffix
        if (SA12[t] < n0 ?
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]) :
            leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0])) { // suffix from SA12 is smaller
            SA[k] = i;  t++;
            if (t == n02) { // done --- only SA0 suffixes left
                for (k++; p < n0; p++, k++) SA[k] = SA0[p];
            }
        }
        else {
            SA[k] = j;  p++;
            if (p == n0) { // done --- only SA12 suffixes left
                for (k++; t < n02; t++, k++) SA[k] = GetI();
            }
        }
    }
#undef GetI
}

class compact_min_segment_tree {
    int n;
    int UNIQUE = 93136074;
    vector<int> tree;
public:
    compact_min_segment_tree(int size) : n(size), tree(2 * size, UNIQUE) {}
    compact_min_segment_tree(const vector<int>& values) : compact_min_segment_tree(values.size()) {
        for (int i = 0; i < n; i++) modify(i, values[i]);
    }
    int function(int a, int b) {
        if (a == UNIQUE) return b;
        else if (b == UNIQUE) return a;
        return (a < b) ? a : b; // minimum value over a range
    }

    // Adjust point i by a value, O(log(n))
    void modify(int i, int value) {
        tree[i + n] = function(tree[i + n], value);
        for (i += n; i > 1; i >>= 1) {
            tree[i >> 1] = function(tree[i], tree[i ^ 1]);
        }
    }

    // Query interval [l, r), O(log(n))
    int query(int l, int r) {
        int res = UNIQUE;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = function(res, tree[l++]);
            if (r & 1) res = function(res, tree[--r]);
        }
        if (res == UNIQUE) throw runtime_error("UNIQUE should not be the return value.");
        return res;
    }
};

struct suffix_rank_tuple {
    int firstHalf, secondHalf, originalIndex;

    bool operator<(const suffix_rank_tuple& other) {
        if (firstHalf == other.firstHalf) return secondHalf < other.secondHalf;
        return firstHalf < other.firstHalf;
    }
};

struct suffix_array {
    vector<int> sa;
    vector<int> lcp;
    vector<int> T;
    int N;

    suffix_array(const string& str) : N(str.size()) {
        T.assign(N, 0);
        for (int i = 0; i < N;i++) {
            T[i] = str[i];
        }
    }

    suffix_array(const vector<int>& T) : N(T.size()), T(T) {}

    void construct_sa() {
        sa.assign(N, 0);
        vector<suffix_rank_tuple> ranks(N);
        vector<int> suffixRanks = T;

        // O(log(n))
        for (int pos = 1; pos < N; pos *= 2) {
            for (int i = 0; i < N; i++) {
                ranks[i].firstHalf = suffixRanks[i];
                ranks[i].secondHalf = i + pos < N ? suffixRanks[i + pos] : -1;
                ranks[i].originalIndex = i;
            }

            // O(nlog(n))
            sort(ranks.begin(), ranks.end());

            int newRank = 0;
            suffixRanks.assign(N, 0);
            suffixRanks[ranks[0].originalIndex] = 0;

            for (int i = 1; i < N; i++) {
                if (ranks[i].firstHalf != ranks[i - 1].firstHalf || ranks[i].secondHalf != ranks[i - 1].secondHalf) newRank++;
                suffixRanks[ranks[i].originalIndex] = newRank;
            }

            if (newRank == N - 1) break;
        }
        for (int i = 0; i < N; i++) sa[i] = ranks[i].originalIndex;
    }

    void construct_lcp() {
        lcp.assign(N, 0);
        vector<int> inv(N);
        for (int i = 0; i < N; i++) inv[sa[i]] = i;
        for (int i = 0, len = 0; i < N; i++) {
            if (inv[i] > 0) {
                int k = sa[inv[i] - 1];
                while ((i + len < N) && (k + len < N) && T[i + len] == T[k + len]) len++;
                lcp[inv[i]] = len;
                if (len > 0) len--;
            }
        }

    }
};

string retrieveString(int i, int len, const vector<int>& text, int shift) {
    string str(len, ' ');
    for (int j = 0; j < len; j++) str[j] = (char)(text[i + j] - shift);
    return str;
}

ifstream in("C:/Users/Toma/Downloads/rosalind_lcsm.txt");
int main() {
    vector<string> strings;
    auto fasta = rosalind::getFasta(in);
    for (auto& [name, str] : fasta) {
        strings.push_back(str);
    }
    strings = { "willy", "winners" };
    int num_sentinels = strings.size();
    int n = num_sentinels;
    for (auto& str : strings) n += str.size();


    vector<int> imap(n);
    int lowest_ascii_value = INT_MAX, highest_ascii_value = INT_MIN;
    for (int i = 0, k = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings[i].size(); j++) {
            int asciiVal = strings[i][j];
            lowest_ascii_value = min(lowest_ascii_value, (int)strings[i][j]);
            highest_ascii_value = max(highest_ascii_value, (int)strings[i][j]);
            imap[k++] = i;
        }
        imap[k++] = i; // ith sentinel belongs to string i
    }


    int shift = num_sentinels - lowest_ascii_value;


    vector<int> text(n);
    vector<int> s(n + 3), SA(n + 3); // There needs to be 3 extra zeroes at the end
    int sentinel = 0;
    for (int i = 0, k = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings[i].size(); j++) {
            text[k] = strings[i][j] + shift;
            s[k] = text[k] + 1;
            k++;
        }
        text[k] = sentinel;
        s[k] = text[k] + 1;
        sentinel++;
        k++;
    }
    suffixArray(s, SA, n, 1 + highest_ascii_value - lowest_ascii_value + num_sentinels);
    SA.pop_back();
    SA.pop_back();
    SA.pop_back();


    suffix_array bruh(text);
    bruh.construct_sa();
    bruh.construct_lcp();
    auto sa = bruh.sa;
    cout << (SA == sa) << endl;

    //cout << sa;
    auto lcp = bruh.lcp;
    int k = strings.size();
    compact_min_segment_tree tree(bruh.lcp);

    set<string> lcss;
    int best_lcs_len = 0;
    int lo = num_sentinels; // inclusive
    int hi = num_sentinels; // exclusive

    map<int, int> col_count;


    // window is on the interval [lo, hi)
    while (true) {
        bool shrinkWindow = hi == n || col_count.size() >= k;
        if (shrinkWindow) {
            int col = imap[sa[lo]];
            if (--col_count[col] == 0) col_count.erase(col);
            lo++;
        }
        else {
            int col = imap[sa[hi]];
            col_count[col]++;
            hi++;
        }
        cout << lo << ' ' << hi << '\n';
        if (lo == n - 1) break;

        if (hi - lo <= 1) continue;
        // min query on the interval [lo + 1, hi] (lo + 1 because first lcp value in window is not used)
        int min_window_lcp = tree.query(lo + 1, hi);

        if (col_count.size() < k) continue;

        if (min_window_lcp > best_lcs_len) {
            best_lcs_len = min_window_lcp;
            lcss.clear();
        }
        if (min_window_lcp == best_lcs_len) {
            lcss.insert(retrieveString(sa[lo], min_window_lcp, text, shift));
        }
    }
    for (auto& i : lcss) cout << i << ' ';
    cout << endl;

}