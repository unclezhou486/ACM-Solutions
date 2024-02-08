#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+10;

int n,w,k;

int id[N];
int rk[N];

long double a[N];
long double ans[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>w;
    long double res=1.0/w;
    a[1]=1;
    for(int i=1;i<=n;i++){
        id[i]=1;
        ans[i]=0;
    }
    rk[1]=1;
    for(int i=1;i<=w;i++){
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            int idx=id[x];
            ans[x]+=a[idx];
            ans[x]-=1.0*rk[idx]*res*(w-i+1);
            rk[idx]++;
            a[idx]+=(res*(w-i+1));
            id[x]+=1;
            if(a[id[x]]==0){
                a[id[x]]=res*(w-i+1);
                rk[id[x]]=1;
            }
            ans[x]-=(a[id[x]]-res*rk[id[x]]*(w-i+1));
        }
    }
    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(7);
        cout<<ans[i]+a[id[i]]<<'\n';
    }
}
