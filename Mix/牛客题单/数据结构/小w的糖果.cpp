#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
const int mod=1e9+7;

int a[N];
int a1[N],a2[N],a3[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) a1[i]=a2[i]=a3[i]=0;
    int res1=0,res2=0,res3=0;
    for(int i=1;i<=m;i++){
        int op,pos;
        cin>>op>>pos;
        if(op==1){
            a1[pos]++;
        }
        else if(op==2) a2[pos]++;
        else a3[pos]++;
    }
    int x=0;
    int res22=0;
    int res33=0;
    int res333=0;
    for(int i=1;i<=n;i++){
        x+=a1[i]+a2[i];
        x%=mod;
        x+=res22;
        x%=mod;
        res22+=a2[i];
        res22%=mod;
        res33+=res333*2;
        res333+=a3[i];
        res33+=a3[i];
        res333%=mod;
        res33%=mod;

        x+=res33;
        x%=mod;
        cout<<x<<' ';
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}