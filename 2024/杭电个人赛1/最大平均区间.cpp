#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
const int M=4e6;
int n,k;
int a[N],s[N];
int p[N];
int a1[N];

int nex[N*30][2],root,tot;
int maxn[N*30];

int newcode(){return tot++;}

void init(){
    for(int i=0;i<=tot;i++){
        nex[i][0]=nex[i][1]=0;
        maxn[i]=-1e18;
    }
    tot=1;
    root=newcode();
}

void insert(int x,int v){
    int p=root;
    for(int i=30;~i;i--){
        int t=(x>>i)&1;
        if(!nex[p][t]) nex[p][t]=newcode();
        p=nex[p][t];
        maxn[p]=max(maxn[p],v);
    }

}

bool query(int x,int k,int val){
    int p=root;
    int res=0;
    for(int i=30;~i;i--){
        int t=(x>>i)&1;
        int res=(k>>i)&1;
        if(res==1){
            if(nex[p][t^1]){
                p=nex[p][t^1];
            }
            else return 0;
        }
        else{
            if(nex[p][t^1]){
                if(maxn[nex[p][t^1]]>=val) return 1;
            }
            if(nex[p][t]){
                p=nex[p][t];
            }
        }
    }
    return (maxn[p]>=val);
}

bool check(int x){
    init();
    for(int i=1;i<=n;i++){
        a1[i]=a[i]-x;
        s[i]=a1[i]+s[i-1];
    }
    for(int i=n;i>=1;i--){
        insert(p[i],s[i]);
        if(query(p[i],k,s[i-1])) return 1;
    }
    return 0;
    //for(int i=1;i<=n;i++){
    //    if(query(p[i],k,s[i-1])) return 1;
    //}
    //return 0;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<=n*30;i++) maxn[i]=-1e18;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    int l=-1,r=987654321;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
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