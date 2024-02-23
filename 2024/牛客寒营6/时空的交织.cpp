#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n,m;

int a[N],b[N];
int s1[N],s2[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s1[i]=s1[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        s2[i]=s2[i-1]+b[i];
    }
    //for(int i=1;i<=m;i++){
    //    cout<<s2[i]<<' ';
    //}
    //cout<<'\n';
    int minsa=a[1],maxsa=a[1];
    int minaa=a[1],maxaa=a[1];
    for(int i=2;i<=n;i++){
        minaa=min({s1[i]-minsa,s1[i]-maxsa,s1[i],minaa});
        maxaa=max({s1[i]-minsa,s1[i]-maxsa,s1[i],maxaa});
        minsa=min(minsa,s1[i]);
        maxsa=max(maxsa,s1[i]);
    }
    int minsb=b[1],maxsb=b[1];
    int minab=b[1],maxab=b[1];
    for(int i=2;i<=m;i++){
        minab=min({s2[i]-minsb,s2[i]-maxsb,s2[i],minab});
        maxab=max({s2[i]-minsb,s2[i]-maxsb,s2[i],maxab});
        minsb=min(minsb,s2[i]);
        maxsb=max(maxsb,s2[i]);
    }
    //cout<<maxaa<<' '<<minaa<<' '<<maxab<<' '<<minab<<'\n';
    cout<<max({minaa*minab,minaa*maxab,maxaa*minab,maxaa*maxab});
}