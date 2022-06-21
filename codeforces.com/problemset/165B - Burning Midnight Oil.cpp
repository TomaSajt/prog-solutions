#include<iostream>
int main(){
    int n,k,v,s,a=0,i=31;
    std::cin>>n>>k;
    for(;i--;a+=(s<n)<<i){
        v=a+(1<<i),s=0;
        do s+=v;while(v/=k);
    }
    std::cout<<a+1;
}