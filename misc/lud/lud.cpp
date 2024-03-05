#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, int> szimulal(int jatekosszam, const string& osveny, const vector<int>& dobasok) {
  vector<int> poziciok(jatekosszam, -1);
  int dobas_ind = 0;
  int korok = 0;
  bool game_over = 0;
  while (!game_over) {
    for (int i = 0; i < jatekosszam; i++) {
      int kovi_poz = poziciok[i] + dobasok[dobas_ind];
      if (kovi_poz >= osveny.length() - 1 || osveny[kovi_poz] == 'M') poziciok[i] += dobasok[dobas_ind];
      else if (osveny[kovi_poz] == 'E') poziciok[i] += 2 * dobasok[dobas_ind];
      if (poziciok[i] >= osveny.length() - 1) game_over = 1;
      dobas_ind++;
    }
    korok++;
  }
  return {poziciok, korok};
}

int main() {

  ifstream dobasok_stream("dobasok.txt");
  ifstream osvenyek_stream("osvenyek.txt");
  vector<int> dobasok;
  vector<string> osvenyek;
  int x;
  string s;
  while (dobasok_stream >> x) dobasok.push_back(x);
  while (osvenyek_stream >> s) osvenyek.push_back(s);

  cout << "2. feladat\n";
  cout << "A dobások száma: " << dobasok.size() << '\n';
  cout << "Az ösvények száma: " << osvenyek.size() << '\n';

  cout << '\n';
  cout << "3. feladat\n";
  auto max_ind = max_element(osvenyek.begin(), osvenyek.end(), [](auto a, auto b) { return a.length() < b.length(); }) - osvenyek.begin();
  cout << "Az egyik leghosszabb a(z) " << max_ind + 1 << ". ösvény, hossza: " << osvenyek[max_ind].length() << '\n';

  cout << '\n';
  cout << "4. feladat\n";
  cout << "Adja meg egy ösvény sorszámát! ";
  int osveny_ind;
  cin >> osveny_ind;
  string osveny = osvenyek[osveny_ind - 1];
  cout << "Adja meg a játékosok számát! ";
  int jatekosszam;
  cin >> jatekosszam;

  cout << '\n';
  cout << "5. feladat\n";
  map<char, int> cnt;
  for (char c : osveny) cnt[c]++;
  for (auto [c, k] : cnt) cout << c << ": " << k << " darab\n";

  ofstream kulonleges_stream("kulonleges.txt");
  for (int i = 0; i < osveny.length(); i++) {
    if (osveny[i] == 'M') continue;
    kulonleges_stream << i + 1 << '\t' << osveny[i] << '\n';
  }

  cout << '\n';
  cout << "7. feladat\n";
  string kamu_osveny(osveny.length(), 'M');
  auto [kamu_poz, kamu_kor] = szimulal(jatekosszam, kamu_osveny, dobasok);
  int kamu_max_tav = *max_element(kamu_poz.begin(), kamu_poz.end());
  cout << "A játék a(z) " << kamu_kor << ". körben fejeződött be. A legtávolabb jutó(k) sorszáma: ";
  for (int i = 0; i < jatekosszam; i++) {
    if (kamu_poz[i] != kamu_max_tav) continue;
    cout << i + 1 << ' ';
  }
  cout << '\n';

  cout << '\n';
  cout << "8. feladat\n";
  auto [poz, kor] = szimulal(jatekosszam, osveny, dobasok);
  int max_tav = *max_element(poz.begin(), poz.end());
  cout << "Nyertes(ek): ";
  for (int i = 0; i < jatekosszam; i++) {
    if (poz[i] < osveny.length() - 1) continue;
    cout << i + 1 << ' ';
  }
  cout << '\n';
  cout << "A többiek pozíciója:\n";
  for (int i = 0; i < jatekosszam; i++) {
    if (poz[i] >= osveny.length() - 1) continue;
    cout << i + 1 << ". játékos, " << poz[i] + 1 << ". mező\n";
  }
}
