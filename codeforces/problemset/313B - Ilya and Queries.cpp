#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
int n,l,r,i=1;
cin>>s>>n;
n=s.size();
vector<int>a(n+1);
for(;i<n;i++)a[i+1]=a[i]+(s[i]==s[i-1]);
while(cin>>l>>r)cout<<a[r]-a[l]<<'\n';
}