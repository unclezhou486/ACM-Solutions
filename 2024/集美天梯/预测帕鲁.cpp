#include <bits/stdc++.h>

using namespace std;

const int N=5e2+10;

int n,a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x,y;
    cin>>x>>y;
    int res=(a[x]+a[y]+1)/2;
    int ans=-1;
    int ansx;
    for(int i=1;i<=n;i++){
        if(ans==-1){
            ans=i;
            ansx=abs(res-a[i]);
        }
        if(ansx>abs(res-a[i])){
            ans=i,ansx=abs(res-a[i]);
        }
    }
    cout<<ans<<'\n';
}