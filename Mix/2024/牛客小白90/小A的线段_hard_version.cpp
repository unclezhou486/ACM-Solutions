#include <bits/stdc++.h>

using namespace std;

const int N=4e2+10;
const int mod=998244353;

int dp[N][N][N];

void add(int &x,int y){
    x=(x+y)%mod;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> vec;
    vector<int> s(m+1),t(m+1);
    for(int i=1;i<=m;i++){
        cin>>s[i]>>t[i];
        s[i]--;
        vec.push_back(s[i]),vec.push_back(t[i]);
    }
    vec.push_back(0),vec.push_back(n);
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    n=vec.size();
    vector<pair<int,int> > a(m+1);
    for(int i=1;i<=m;i++){
        s[i]=lower_bound(vec.begin(),vec.end(),s[i])-vec.begin();
        t[i]=lower_bound(vec.begin(),vec.end(),t[i])-vec.begin();
        a[i]={s[i],t[i]};
    }
    sort(a.begin()+1,a.end());
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                if(!dp[i-1][l][r]) continue;
                add(dp[i][l][r],dp[i-1][l][r]);
                if(a[i].first<=l){
                    add(dp[i][max(l,min(a[i].second,r))][max(a[i].second,r)],dp[i-1][l][r]);
                }
            }
        }
    }
    cout<<dp[m][n-1][n-1]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}