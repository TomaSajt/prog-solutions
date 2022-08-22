#include "_helpers.hpp"

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
            if ((l & 1) != 0) res = function(res, tree[l++]);
            if ((r & 1) != 0) res = function(res, tree[--r]);
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

class suffix_array {
public:
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

ifstream in("C:/Users/Toma/Downloads/rosalind_lcsm(2).txt");
int main() {
    vector<string> strings;
    auto fasta = rosalind::getFasta(in);
    for (auto& [name, str] : fasta) {
        strings.push_back(str);
    }

    int num_sentinels = strings.size();
    int total_length = num_sentinels;
    for (auto& str : strings) total_length += str.size();


    vector<int> imap(total_length);
    int lowest_ascii_value = INT_MAX, highest_ascii_value = INT_MIN;
    for (int i = 0, k = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings[i].length(); j++) {
            int asciiVal = strings[i][j];
            lowest_ascii_value = min(lowest_ascii_value, (int)strings[i][j]);
            highest_ascii_value = max(highest_ascii_value, (int)strings[i][j]);
            imap[k++] = i;
        }
        // ith sentinel belongs to string i
        imap[k++] = i;
    }


    int shift = num_sentinels - lowest_ascii_value;


    vector<int> text(total_length);
    int sentinel = 0;
    for (int i = 0, k = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings[i].size(); j++) {
            text[k++] = strings[i][j] + shift;
        }
        text[k++] = sentinel++;
    }
    suffix_array bruh(text);
    bruh.construct_sa();
    bruh.construct_lcp();
    auto sa = bruh.sa;
    auto lcp = bruh.lcp;
    int k = strings.size();
    compact_min_segment_tree tree(bruh.lcp);

    set<string> lcss;
    int best_lcs_len = 0;
    int lo = num_sentinels;
    int hi = num_sentinels;

    map<int, int> col_count;

    col_count[imap[sa[hi]]]++;

    while (true) {
        bool shrinkWindow = (hi == total_length - 1) || col_count.size() >= k;
        if (shrinkWindow) {
            int col = imap[sa[lo]];
            if (--col_count[col] == 0) col_count.erase(col);
            lo++;
        }
        else {
            hi++;
            int col = imap[sa[hi]];
            col_count[col]++;
        }

        if (lo == total_length - 1) break;

        if (lo == hi) continue;
        // min query on the interval [lo + 1, hi] (lo + 1 because first lcp value in window is not used)
        int min_window_lcp = tree.query(lo + 1, hi + 1);

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