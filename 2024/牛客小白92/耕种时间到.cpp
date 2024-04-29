#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

set<int> se;
map<int,long long> ma;

int n,x;

long long ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        se.insert(x);
        ma[x]+=1;
    }
    cin>>x;
    ans=max(ans,ma[x]);
    for(int i=1;i<=30;i++){
        set<int> see;
        map<int,long long> maa;
        for(auto v:se){
            see.insert((v+2)/3);
            maa[(v+2)/3]+=2ll*ma[v];
        }
        se=see;
        ma=maa;
        ans=max(ans,ma[x]);
    }
    cout<<ans<<'\n';
}