#include <bits/stdc++.h>

using namespace std;

string s;

int ans=0;
int res=0;

int main(){
    cin>>s;
    for(auto v:s){
        if(v=='1') res++;
        else res=0;
        if(res==0) {ans-=12;continue;}
        ans+=3;
        if(res<=6) ans+=(res-1);
        else ans+=5;
    }
    cout<<ans<<'\n';
}