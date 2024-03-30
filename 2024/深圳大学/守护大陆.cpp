#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;

int n,m;

int a[N],b[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int res1,res2;
    res1=a[n/2+1];
    res2=b[m/2+1];
    if(res1*n>res2*m){
        cout<<"Yes\n";
    }
    else if(res1*n==res2*m){
        cout<<"NY\n";
    }
    else cout<<"No\n";
}