#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
//int v[N];
//vector<pair<>
map<int,int> maa;
map<int,vector<pair<int,int> > > ma;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> w(n+2);
    vector<int> v(n+2);
    vector<int> x(m+1);
    vector<int> res(m+1);
    for(int i=n;i>=1;i--){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        w[i]+=w[i-1];
    }
    w[n+1]=1e18;
    for(int i=n;i>=1;i--){
        cin>>v[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=m;j++){
            ma[w[i-1]+x[j]].push_back({j,i});
        }
    }
    int num=0;
    maa[num]=1;
    int cnt=1;
    for(auto [a,b]:ma){
        //cout<<a<<' ';
        for(auto c:b){
            num-=res[c.first];
            res[c.first]=v[c.second];
            num+=res[c.first];
        }
        //cout<<num<<'\n';
        if(!maa.count(num)) cnt++;
        maa[num]=1;
    }
    cout<<cnt<<'\n';
}