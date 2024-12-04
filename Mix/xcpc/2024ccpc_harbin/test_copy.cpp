#include <bits/stdc++.h>
#define int long long

using namespace std;
#define ll long long 

const ll N=3000007;
const ll mod=1e9+7;


ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}


    #define poly vector<ll>
    
    poly poly_mul(poly A,poly B){
        ll deg=A.size()+B.size()-1;
        poly C(deg);
        for(int i=0;i<A.size();i++){
            for(int u=0;u<B.size();u++){
                C[i+u]+=A[i]*B[u]%mod;
                C[i+u]%=mod;
            }
        }
        return C;
    }
    poly poly_inv(poly &f,ll deg){
        if(deg==1){
            return poly(1,qpow(f[0],mod-2));
        }
        poly A(f.begin(),f.begin()+deg);
        poly B=poly_inv(f,(deg+1)>>1);
        poly BB=B;
        poly C=poly_mul(A,BB);
        for(int i=0;i<C.size();i++){
            if(i==0){
                C[i]=((2-C[i])%mod+mod)%mod;
            }else C[i]=(mod-C[i])%mod;

        }
        poly D=poly_mul(B,C);
        D.resize(deg);
        return D;
    }

struct fs{
    int fz,fm;
    bool operator<(const fs& a)const{
        return fz*a.fm<a.fz*fm;
    }
};
void solve(){
    // cout<<"test\n";
    int n,m;
    cin>>n>>m;
    vector<int> x(n+1),v(m+1);
    for(int i=1;i<=n;i++)cin>>x[i],x[i]*=-1;
    for(int i=1;i<=m;i++)cin>>v[i];
    vector<vector<fs>> t(n+1,vector<fs>(m+1));
    vector<pair<fs,int>> tt(n*m+1);
    for(int i=1;i<=n;i++){
        for(int u=1;u<=m;u++){
            int _=gcd(x[i],v[u]);
            t[i][u]={x[i]/_,v[u]/_};
            tt[(i-1)*m+u]={t[i][u],u};
        }
    }
    sort(tt.begin()+1,tt.end());
    vector<int> ans,pre(m+1);


    ans.push_back(qpow(n,m));
    int ansval=0;
    for(int i=1;i<=n*m;i++){
        for(int u=1;u<=m;u++){
            int lst=pre[u];
            while(pre[u]+1<=n&&!(tt[i].first<t[pre[u]+1][u]))pre[u]++;
            if(lst==pre[u])continue;
            vector<int>_;
            _.push_back(n-lst);
            _.push_back(lst);
            ans=poly_mul(ans,poly_inv(_,2));
            _.resize(0);
            _.push_back(n-pre[u]);
            _.push_back(pre[u]);
            ans=poly_mul(ans,_);
        }
        int lst=pre[tt[i].second];
        vector<int> _,as;
        _.push_back(n-lst);
        _.push_back(lst);
        vector<int> __=poly_inv(_,2);
        as=poly_mul(ans,__);


        if(as.size()<=m/2)continue;
        ansval+=((as[m/2]*tt[i].first.fz)%mod)*qpow(tt[i].first.fm,mod-2)%mod;
        ansval%=mod;
    }
    cout<<ansval<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}