#include <bits/stdc++.h>
#define int long long
using namespace std;



void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n+1);
    vector<int> s(n+1);
    map<int,int> ma;
    set<int> se;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        se.insert(s[i]);
        se.insert(s[i]-l);
        se.insert(s[i]-r);
        //se.insert()
    }
    se.insert(0);
    int cnt=0;
    for(auto x:se){
        ma[x]=++cnt;
    }
    int m=3*(n+10);
    vector<int> b(m);
    auto lowbit = [&] (int x) -> int {
        return x&(-x);
    };
    auto add = [&] (int k,int x) -> void {
        for(;k<=m;k+=lowbit(k)){
            b[k]+=x;
        }
    };
    auto query = [&] (int x) -> int {
        int res=0;
        for(;x;x-=lowbit(x)){
            res+=b[x];
        }
        return res;
    };
    int ans=0;
    add(ma[0],1);
    for(int i=1;i<=n;i++){
        
        //cout<<ans<<' ';
        ans+=query(ma[s[i]-l])-query(ma[s[i]-r]-1);
        //cout<<ans<<'\n';
        add(ma[s[i]],1);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}