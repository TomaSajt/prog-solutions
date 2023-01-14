// SA-IS algorithm for compting suffix array in O(n) time
// https://www.youtube.com/watch?v=OIuG_Dqyl_s


#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;


struct ReductionSummary {
    vector<int> reducedText;
    vector<int> offsets;
    int alphabetSize;
};

bool s_type = true;
bool l_type = false;

vector<int> buildSuffixArray(const vector<int>& text, int alphabetSize);
void positionLmsCharacters(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes, const vector<int>& summarySuffixArray, const vector<int>& summaryOffsets);
vector<int> buildSummarySuffixArray(const ReductionSummary& summary);
ReductionSummary doReduce(const vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes);
bool areLmsBlocksEqual(const vector<int>& text, int prevOffset, int curOffset, const vector<bool>& suffixTypes);
void inductionSortS(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes);
void inductionSortL(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes);
void positionLmsCharacters(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes);
bool isLmsCharacter(int index, const vector<bool>& suffixTypes);
vector<int> getBucketHeads(const vector<int>& bucketSizes);
vector<int> getBucketTails(const vector<int>& bucketSizes);
vector<int> getBucketSizes(const vector<int>& text, int alphabetSize);
vector<bool> getSuffixTypes(const vector<int>& text);


vector<int> buildSuffixArray(const vector<int>& text, int alphabetSize) {
    vector<bool> suffixTypes = getSuffixTypes(text);
    vector<int> bucketSizes = getBucketSizes(text, alphabetSize);
    int n = text.size();
    vector<int>suffixArray(n + 1, -1);
    positionLmsCharacters(suffixArray, text, suffixTypes, bucketSizes);
    inductionSortL(suffixArray, text, suffixTypes, bucketSizes);
    inductionSortS(suffixArray, text, suffixTypes, bucketSizes);
    ReductionSummary summary = doReduce(suffixArray, text, suffixTypes);
    vector<int> summarySuffixArray = buildSummarySuffixArray(summary);
    suffixArray.assign(n + 1, -1);
    positionLmsCharacters(suffixArray, text, suffixTypes, bucketSizes, summarySuffixArray, summary.offsets);
    inductionSortL(suffixArray, text, suffixTypes, bucketSizes);
    inductionSortS(suffixArray, text, suffixTypes, bucketSizes);
    return suffixArray;
}

void positionLmsCharacters(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes, const vector<int>& summarySuffixArray, const vector<int>& summaryOffsets) {
    suffixArray[0] = text.size();
    vector<int> bucketTails = getBucketTails(bucketSizes);
    for (int i = summarySuffixArray.size() - 1; i > 1; i--) {
        int charIndex = summaryOffsets[summarySuffixArray[i]];
        int bucketIndex = text[charIndex];
        suffixArray[bucketTails[bucketIndex]] = charIndex;
        bucketTails[bucketIndex]--;
    }
}

vector<int> buildSummarySuffixArray(const ReductionSummary& summary) {
    if (summary.alphabetSize == summary.reducedText.size()) {
        vector<int> suffixArray(summary.reducedText.size() + 1);
        suffixArray[0] = summary.reducedText.size();
        for (int i = 1; i < summary.reducedText.size(); i++) {
            suffixArray[summary.reducedText[i] + 1] = i;
        }
        return suffixArray;
    }
    return buildSuffixArray(summary.reducedText, summary.alphabetSize);
}

ReductionSummary doReduce(const vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes) {
    vector<int> lmsNames(text.size() + 1, -1);
    int curName = 0;
    int count = 1;
    lmsNames[suffixArray[0]] = curName;
    int curOffset, prevOffset = suffixArray[0];
    for (int i = 1; i < suffixArray.size(); i++) {
        if (!isLmsCharacter(suffixArray[i], suffixTypes)) continue;
        curOffset = suffixArray[i];
        if (!areLmsBlocksEqual(text, prevOffset, curOffset, suffixTypes)) curName++;
        prevOffset = curOffset;
        lmsNames[curOffset] = curName;
        count++;
    }
    vector<int> reducedText(count);
    vector<int> offsets(count);
    for (int i = 0, j = 0; i < lmsNames.size(); i++) {
        if (lmsNames[i] == -1) continue;
        reducedText[j] = lmsNames[i];
        offsets[j] = i;
        j++;
    }
    return ReductionSummary{ reducedText, offsets, curName + 1 };
}

bool areLmsBlocksEqual(const vector<int>& text, int prevOffset, int curOffset, const vector<bool>& suffixTypes) {
    if (prevOffset == text.size() || curOffset == text.size()) return false;
    if (text[prevOffset] != text[curOffset]) return false;
    int i = 1;
    while (i < text.size()) {
        bool prevIsLms = isLmsCharacter(prevOffset + i, suffixTypes);
        bool curIsLms = isLmsCharacter(curOffset + i, suffixTypes);
        if (prevIsLms && curIsLms) return true;
        if (prevIsLms != curIsLms) return false;
        if (text[prevOffset + i] != text[curOffset + i]) return false;
        i++;
    }
    return false;
}

void inductionSortS(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes) {
    vector<int> bucketTails = getBucketTails(bucketSizes);
    for (int i = suffixArray.size() - 1; i >= 0; i--) {
        int j = suffixArray[i] - 1;
        if (j < 0 || suffixTypes[j] != s_type) continue;
        suffixArray[bucketTails[text[j]]] = j;
        bucketTails[text[j]]--;
    }
}

void inductionSortL(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes) {
    vector<int> bucketHeads = getBucketHeads(bucketSizes);
    for (int i = 0; i < suffixArray.size(); i++) {
        int j = suffixArray[i] - 1;
        if (j < 0 || suffixTypes[j] != l_type) continue;
        suffixArray[bucketHeads[text[j]]] = j;
        bucketHeads[text[j]]++;
    }
}

void positionLmsCharacters(vector<int>& suffixArray, const vector<int>& text, const vector<bool>& suffixTypes, const vector<int>& bucketSizes) {
    suffixArray[0] = text.size();
    vector<int> bucketTails = getBucketTails(bucketSizes);
    for (int i = text.size() - 1; i >= 0; i--) {
        if (!isLmsCharacter(i, suffixTypes)) continue;
        suffixArray[bucketTails[text[i]]] = i;
        bucketTails[text[i]]--;
    }
}

bool isLmsCharacter(int index, const vector<bool>& suffixTypes) {
    if (index == 0) return false;
    return suffixTypes[index] == s_type && suffixTypes[index - 1] == l_type;
}

vector<int> getBucketHeads(const vector<int>& bucketSizes) {
    vector<int> heads(bucketSizes.size());
    int offset = 1;
    for (int i = 0; i < bucketSizes.size(); i++) {
        heads[i] = offset;
        offset += bucketSizes[i];
    }
    return heads;
}

vector<int> getBucketTails(const vector<int>& bucketSizes) {
    vector<int> tails(bucketSizes.size());
    int offset = 1;
    for (int i = 0; i < bucketSizes.size(); i++) {
        offset += bucketSizes[i];
        tails[i] = offset - 1;
    }
    return tails;
}

vector<int> getBucketSizes(const vector<int>& text, int alphabetSize) {
    vector<int> sizes(alphabetSize);
    for (int ch : text) {
        sizes[ch]++;
    }
    return sizes;
}

vector<bool> getSuffixTypes(const vector<int>& text) {
    int n = text.size();
    vector<bool> types(n + 1);
    types[n] = s_type;
    if (n == 0) return types;
    types[n - 1] = l_type;
    for (int i = n - 2; i >= 0; i--) {
        if (text[i] < text[i + 1]) {
            types[i] = s_type;
        }
        else if (text[i] > text[i + 1]) {
            types[i] = l_type;
        }
        else {
            types[i] = types[i + 1];
        }
    }
    return types;
}


int main() {
    speed;
    string s; cin >> s;

    int n = s.size();
    vector<int> data(n);
    for (int i = 0; i < n; i++) data[i] = (int)s[i];
    int mi = *min_element(data.begin(), data.end());
    for (int i = 0; i < n; i++) data[i] -= mi;
    int ma = *max_element(data.begin(), data.end());
    vector<int> sa = buildSuffixArray(data, ma + 1);


    vector<int> lcp(n + 1), inv(n + 1);
    for (int i = 0; i <= n; i++) inv[sa[i]] = i;
    for (int i = 0, len = 0; i <= n; i++) {
        if (inv[i] == 0) continue;
        int k = sa[inv[i] - 1];
        while ((i + len < n) && (k + len < n) && data[i + len] == data[k + len]) len++;
        lcp[inv[i]] = len;
        if (len > 0) len--;
    }
    for (int i = 0; i <= n; i++) {
        cout << "i=" << i << "; sa[i]=" << sa[i] << "; lcp[i]=" << lcp[i] << "; suffix: {" << s.substr(sa[i]) << "}\n";
    }
}