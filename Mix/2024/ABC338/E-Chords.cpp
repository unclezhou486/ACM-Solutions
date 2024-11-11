#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=4e5+10;

int n;
int l[N],r[N];

int b[N];

int lowbit(int x){
    return x&(-x);
}

void add(int k,int x){
    for(;k<=2*n;k+=lowbit(k)){
        b[k]+=x;
    }
}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)){
        res+=b[x];
    }
    return res;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        if(l[i]>r[i]) swap(l[i],r[i]);
        add(l[i],1);
        add(r[i],-1);
    }
    for(int i=1;i<=n;i++){
        //cout<<r[i]-1<<' '<<l[i]<<' ';
        //cout<<query(r[i]-1)<<' '<<query(l[i])<<'\n';
        if(query(r[i]-1)-query(l[i])){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
    return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}