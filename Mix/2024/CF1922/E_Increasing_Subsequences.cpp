#include <bits/stdc++.h>

using namespace std;

pair<pair<vector<int>,int>,int> f(long long x){
    vector<int> res;
    long long maxn=0,minn=0;
    if(x==2){
        res.push_back(0);
    }
    else if(x%2){
        auto pos=f(x-1);
        res=pos.first.first;
        maxn=pos.first.second;
        minn=pos.second;
        res.push_back(minn-1);
        minn-=1;
    }
    else{
        auto pos=f(x/2);
        res=pos.first.first;
        maxn=pos.first.second;
        minn=pos.second;
        res.push_back(maxn+1);
        maxn+=1;
    }
    return {{res,maxn},minn};
}

void solve(){
    long long n;
    cin>>n;
    auto ans=f(n).first.first;
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}