#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;

int n,m,k;

int a[N];
int ne[N];
int ans[N];
int tmp[N];
int h,t;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    h=1,t=k+1;
    ne[1]=k+1;
    for(int i=2;i<=n;i++){
        while(t<n&&a[t+1]-a[i]<a[i]-a[h]) h++,t++;
        if(a[t]-a[i]<=a[i]-a[h]) ne[i]=h;
        else ne[i]=t;
    }
    for(int i=1;i<=n;i++) ans[i]=i;
    while(m){
        if(m&1){
            for(int i=1;i<=n;i++){
                ans[i]=ne[ans[i]];
            }
        }
        memcpy(tmp,ne,sizeof tmp);
        for(int i=1;i<=n;i++){
            ne[i]=tmp[tmp[i]];
        }
        m>>=1;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    return 0;
}