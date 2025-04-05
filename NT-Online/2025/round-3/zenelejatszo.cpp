#include <bits/stdc++.h>
using namespace std;
#define int int64_t

map<string, int> id_map;
map<int, int> len_map;

int get_id(string name) {
  if (id_map.count(name)) return id_map[name];
  return id_map[name] = id_map.size();
}

int total_song_len = 0;
set<pair<int, int>, greater<pair<int, int>>> ts_song_id;

vector<int> id_to_added_ts;
vector<int> times_played;

int _ts = 0;
void add_rem_song(int song_id) {
  _ts++;
  if (id_to_added_ts[song_id] != -1) {
    cerr << "removing " << song_id << endl;
    ts_song_id.erase({id_to_added_ts[song_id], song_id});
    total_song_len -= len_map[song_id];
    id_to_added_ts[song_id] = -1;
  }
  else {
    cerr << "adding " << song_id << endl;
    id_to_added_ts[song_id] = _ts;
    ts_song_id.insert({_ts, song_id});
    total_song_len += len_map[song_id];
  }
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int q;
  cin >> q;

  vector<pair<char, int>> ops(q);
  for (auto& [o, v] : ops) {
    cin >> o;
    if (o == 'P') {
      cin >> v;
      continue;
    }
    string name;
    cin >> name;
    v = get_id(name);
    if (o == 'L') {
      cin >> len_map[v];
    }
  }

  int k = id_map.size();

  id_to_added_ts.assign(k, -1);
  times_played.assign(k, 0);

  for (auto [o, v] : ops) {
    cerr << o << ' ' << v << endl;
    if (o == 'L') {
      add_rem_song(v);
      for (auto [_, song_id] : ts_song_id) {
        cerr << song_id << ' ';
      }
      cerr << endl;
      cerr << "total_len: " << total_song_len << endl;
    }
    else if (o == 'P') {
      int cycles = v / total_song_len;
      for (auto [_, song_id] : ts_song_id) {
        times_played[song_id] += cycles;
        cerr << "played " << song_id << " " << cycles << " times" << endl;
      }
      int rem = v % total_song_len;

      int asd = 0;
      for (auto [_, song_id] : ts_song_id) {
        asd += len_map[song_id];
        if (asd > rem) break;
        times_played[song_id]++;
        cerr << "played " << song_id << endl;
      }
    }
    else if (o == 'Q') {
      cerr << "query res:" << endl;
      cout << times_played[v] << endl;
    }
  }
}
