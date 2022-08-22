#include "_helpers.hpp"


// The code is mostly based on William Fiset's LongestCommonSubstring implementation, however this version has multiple improvements over that
// Link: https://github.com/williamfiset/Algorithms/blob/347b0bf6e5712f012334b708d793d6904e8b82cf/src/main/java/com/williamfiset/algorithms/strings/LongestCommonSubstring.java
//
// o(n) suffix array compute method from https://www.cs.cmu.edu/~guyb/realworld/papersS04/KaSa03.pdf


inline bool leq(int a1, int a2, int b1, int b2) { // lexic. order for pairs
    return(a1 < b1 || a1 == b1 && a2 <= b2);
}                                                   // and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
void radix_pass(const vector<int>& a, vector<int>& b, const vector<int>& r, int r_offset, int n, int K) { // count occurrences
    vector<int> c(K + 1, 0);
    for (int i = 0; i < n; i++) c[r[a[i] + r_offset]]++;    // count occurences
    for (int i = 0, sum = 0; i <= K; i++) { // exclusive prefix sums
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0; i < n; i++) b[c[r[a[i] + r_offset]]++] = a[i];      // sort
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void compute_suffix_array(vector<int>& s, vector<int>& SA, int n, int K) {
    int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
    vector<int> s12(n02 + 3, 0), SA12(n02 + 3, 0), s0(n0), SA0(n0);

    // generate positions of mod 1 and mod  2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i = 0, j = 0; i < n + (n0 - n1); i++) if (i % 3 != 0) s12[j++] = i;

    // lsb radix sort the mod 1 and mod 2 triples
    radix_pass(s12, SA12, s, 2, n02, K);
    radix_pass(SA12, s12, s, 1, n02, K);
    radix_pass(s12, SA12, s, 0, n02, K);

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
        compute_suffix_array(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array 
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    }
    else // generate the suffix array of s12 directly
        for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;

    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
    radix_pass(s0, SA0, s, 0, n0, K);

    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
#define GET_I() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GET_I(); // pos of current offset 12 suffix
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
                for (k++; t < n02; t++, k++) SA[k] = GET_I();
            }
        }
    }
#undef GET_I
}

string retrieve_string(int i, int len, const vector<int>& s, int shift) {
    string str(len, ' ');
    for (int j = 0; j < len; j++) str[j] = (char)(s[i + j] - shift);
    return str;
}

void solve(const vector<string>& strings, vector<string>& lcs_list) {
    if (strings.size() == 0) return;
    if (strings.size() == 1) {
        lcs_list.push_back(strings[0]);
        return;
    }
    int num_sentinels = strings.size();
    int n = num_sentinels;
    for (auto& str : strings) n += str.size();

    // compute to which string the ith position in text belongs to
    vector<int> pos_col_map(n);
    int lowest_ascii_value = INT_MAX, highest_ascii_value = INT_MIN;
    for (int i = 0, k = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings[i].size(); j++) {
            int asciiVal = strings[i][j];
            lowest_ascii_value = min(lowest_ascii_value, (int)strings[i][j]);
            highest_ascii_value = max(highest_ascii_value, (int)strings[i][j]);
            pos_col_map[k++] = i;
        }
        pos_col_map[k++] = i; // ith sentinel belongs to string i
    }


    int shift = num_sentinels - lowest_ascii_value + 1; // + 1 because the lowest sentinel has to be at least 1 for compute_suffix_array


    vector<int> text(n + 3), sa(n + 3); // There needs to be 3 extra zeroes at the end for compute_suffix_array
    int sentinel = 1;
    for (int i = 0, k = 0; i < strings.size(); i++) {
        for (int j = 0; j < strings[i].size(); j++) {
            text[k++] = strings[i][j] + shift;
        }
        text[k++] = sentinel++;
    }

    compute_suffix_array(text, sa, n, highest_ascii_value - lowest_ascii_value + num_sentinels + 1);

    // get rid of the 0s at the end
    text.resize(n);
    sa.resize(n);

    // compute longest common prefix array
    vector<int> lcp(n), inv(n);
    for (int i = 0; i < n; i++) inv[sa[i]] = i;
    for (int i = 0, len = 0; i < n; i++) {
        if (inv[i] > 0) {
            int k = sa[inv[i] - 1];
            while ((i + len < n) && (k + len < n) && text[i + len] == text[k + len]) len++;
            lcp[inv[i]] = len;
            if (len > 0) len--;
        }
    }

    // number of strings that need to contain the substring
    // for this problem, we want all the strings to have the substring in common, however this could be any other value too
    int k = strings.size();

    min_sliding_window msw(lcp, num_sentinels);
    msw.shrink(); // shrink once because we want to ignore the first element from the window when querying the minimum

    int best_lcs_len = 0;
    counting_map<int> col_counts;
    int lo = num_sentinels, hi = num_sentinels;

    // window is on the interval [lo, hi)
    while (true) {
        bool shrink_window = hi == n || col_counts.count_different() >= k;
        if (shrink_window) {
            col_counts.dec(pos_col_map[sa[lo++]]);
            msw.shrink();
        }
        else {
            col_counts.inc(pos_col_map[sa[hi++]]);
            msw.advance();
        }
        if (lo == n - 1) break; // end loop when can't shrink anymore
        if (hi - lo < 2) continue; // we can't calculate the minimum of a window size less than 2
        int min_window_lcp = msw.curr_min();

        if (col_counts.count_different() < k) continue;

        if (min_window_lcp >= best_lcs_len) {
            if (min_window_lcp > best_lcs_len) lcs_list.clear();
            best_lcs_len = min_window_lcp;
            lcs_list.push_back(retrieve_string(sa[lo], min_window_lcp, text, shift));
        }
    }
}


ifstream in("C:/Users/Toma/Downloads/rosalind_lcsm.txt");
int main() {
    vector<string> strings;
    auto fasta = rosalind::getFasta(in);
    for (auto& [name, str] : fasta) strings.push_back(str);
    vector<string> solution;
    auto start = chrono::high_resolution_clock::now();
    solve(strings, solution);
    auto end = chrono::high_resolution_clock::now();
    cout << "elapsed time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "found " << solution.size() << " solution" << (solution.size() == 1 ? "" : "s") << ':' << endl;
    for (auto& i : solution) cout << i << endl;
}