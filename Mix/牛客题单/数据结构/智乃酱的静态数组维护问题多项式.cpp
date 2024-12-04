#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+20;
const int mod=1e9+7;

int n,m,q;

int a[N];

int b1[20],b2[20];

int c[20];

void sub(int &x,int y){x=(((x-y)%mod)+mod)%mod;}

int fun(int x,int k){
    int res=0;
    int ress=1;
    for(int i=0;i<=k;i++){
        res+=c[i]*ress;
        res%=mod;
        ress*=x;
        ress%=mod;
    }
    return res;
}

void D(int a[],int len,int cnt){while(cnt--){for(int i=len;i>=1;i--){sub(a[i],a[i-1]);}}}
void P(int a[],int len,int cnt){while(cnt--)for(int i=1;i<=len;i++)a[i]=(a[i]+a[i-1])%mod;}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    D(a,n,6);
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        for(int i=k;i>=0;i--){
            cin>>c[i];
        }
        for(int i=1;i<=15;i++){
            b1[i]=fun(i,k);
            b2[i]=fun(i+(r-l+1),k);
            b2[i]=mod-b2[i];
            sub(b2[i],0);
        }
        D(b1,15,6);
        D(b2,15,6);
        for(int i=1;i<=15;i++){
            a[l+i-1]+=b1[i];
            a[l+i-1]%=mod;
            a[r+i]+=b2[i];
            a[r+i]-=mod;
        }
    }
    P(a,n,7);
    while(q--){
        int l,r;
        cin>>l>>r;
        int res=a[r]-a[l-1];
        sub(res,0);
        cout<<res<<'\n';
    }
}