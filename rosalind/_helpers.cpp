#include "_helpers.hpp"

vector<pair<string, string>> rosalind::getFasta(istream& stream) {
    vector<pair<string, string>> vec;
    while (!stream.eof()) {
        string line;
        getline(stream, line);
        string name = line.substr(1);
        string str = "";
        while (!stream.eof() && stream.peek() != '>') {
            getline(stream, line);
            str += line;
        }
        vec.push_back({ name,str });
    }
    return vec;
}

ostream& operator<<(ostream& stream, const vector<int>& vec) {
    for (auto& i : vec) stream << i << ' ';
    return stream << endl;
}