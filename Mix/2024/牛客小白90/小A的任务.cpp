#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n,q;

int a[N],b[N];

int s[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    while(q--){
        int k;
        cin>>k;
        priority_queue<int> q;
        int res=0;
        for(int i=1;i<=k;i++){
            q.push(b[i]);
            res+=b[i];
        }
        //ans=
        int ans=s[k]+res;
        for(int i=k+1;i<=n;i++){
            q.push(b[i]);
            res+=b[i];
            res-=q.top();
            q.pop();
            ans=min(ans,res+s[i]);
        }
        cout<<ans<<'\n';
    }
}