#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
const int mod=1e9+7;

int n,k,a[N],s[N*31];
int nex[N*31][2],root,tot;

int newcode(){
    memset(nex[tot],0,sizeof nex[tot]);
    s[tot]=0;
    return tot++;
}

void init(){
    memset(nex[0],0,sizeof nex[0]);
    s[0]=0;
    tot=1;
    root=newcode();
}

void insert(int x,int v){
    int p=root;
    for(int i=30;~i;i--){
        int t=(x>>i)&1;
        if(!nex[p][t]) nex[p][t]=newcode();
        p=nex[p][t];
        s[p]=(s[p]+v)%mod;
    }
}

int query(int x,int k){
    int p=root;
    int res=0;
    for(int i=30;~i;i--){
        int t=(x>>i)&1;
        if((k>>i)&1){
            if(nex[p][t]) res=(res+(s[nex[p][t]]))%mod;
            p=nex[p][t^1];
        }
        else{
            p=nex[p][t];
        }
    }
    res=(res+s[p])%mod;
    return res;
}

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

long long inv(long long x){
    return qmi(x,mod-2);
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    init();
    int ans=1;
    for(int i=2;i<=n;i++){
        insert(a[i-1],inv(qmi(2,i-1)));
        ans=(ans+1+query(a[i],k)*qmi(2,i-1))%mod;
    }   
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}