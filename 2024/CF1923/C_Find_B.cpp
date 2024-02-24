#include <bits/stdc++.h>
#define int long long
#define pl tr<<1
#define pr tr<<1|1

using namespace std;

const int N=3e5+10;

int a[N];
int s[N],s1[N];

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        a[i]=s[i]=s1[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if(a[i]==1){
            s1[i]=2;
        }
        else{
            s1[i]=0;
        }
        s1[i]=s1[i-1]+s1[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int res=s1[r]-s1[l-1];
        int ress=s[r]-s[l-1];
        if((ress-res)<(r-l+1)-res/2||l==r){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}