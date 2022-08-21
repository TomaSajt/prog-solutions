#include<bits/stdc++.h>
using namespace std;struct p{long long x,y;};int n,i;vector<p>v;bool l(p a,p b,p c){return(c.y-a.y)*(a.x-b.x)!=(c.x-a.x)*(a.y-b.y);}bool f(int a,int b){vector<p>r;for(i=0;i<n;i++)if(i!=a&&i!=b&&l(v[a],v[b],v[i]))r.push_back(v[i]);if(r.size()<3)return 1;for(i=2;i<r.size();i++)if(l(r[0],r[1],r[i]))return 0;return 1;}int main(){cin>>n;v.resize(n);for(p&a:v)cin>>a.x>>a.y;cout<<(n<5||f(0,1)||f(0,2)||f(1,2)?"YES":"NO");}

/*
#include<bits/stdc++.h>
using namespace std;
struct point { long long x, y; };
int n;
vector<point> p;
inline bool online(int a, int b, int c) { return (p[c].y - p[a].y) * (p[a].x - p[b].x) == (p[c].x - p[a].x) * (p[a].y - p[b].y); }
bool check(int a, int b) {
    vector<int> r;
    for (int i = 0;i < n;i++) {
        if (i != a && i != b && !online(a, b, i)) r.push_back(i);
    }
    if (r.size() < 3) return true;
    for (int i = 2;i < r.size();i++) {
        if (!online(r[0], r[1], r[i])) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    p.resize(n);
    for (auto& a : p) cin >> a.x >> a.y;
    cout << (n < 5 || check(0, 1) || check(0, 2) || check(1, 2) ? "YES" : "NO");
}*/