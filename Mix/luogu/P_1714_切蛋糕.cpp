#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int n,m;

int a[N];
int sum[N];

deque<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    int ans=-1e9;
    q.push_back(0);
    for(int i=1;i<=n;i++){
        while(q.size()&&q.front()<i-m) q.pop_front();
        ans=max(ans,sum[i]-sum[q.front()]);
        while(q.size()&&sum[q.back()]>=sum[i]) q.pop_back();
        q.push_back(i);
    }
    cout<<ans<<'\n';
}