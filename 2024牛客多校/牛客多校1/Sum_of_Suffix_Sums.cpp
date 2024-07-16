#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1000000007;

void solve(){
    int n;
    long long sum=0;
    stack<long long> q;
    cin>>n;
    while(n--){
        long long a,b;
        cin>>a>>b;
        for(int i=1;i<=a;i++){
            sum-=(q.top()*(q.size())%mod);
            sum%=mod;
            q.pop();
        }
        q.push(b);
        sum+=(q.top()*q.size())%mod;
        sum%=mod;
        sum+=mod;
        sum%=mod;
        cout<<sum<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
/*
5
0 1
0 2
1 3
0 6
2 100000
*/