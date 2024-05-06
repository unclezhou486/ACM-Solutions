#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n;
int a[N];
long long s[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    vector<vector<long long > > dp( (n+2) ,vector<long long > ((n<<1)+1) );
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(long long )a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            dp[i][j]=max(s[i]-s[max(0,i-j-1)],s[min(n,i+j)]-s[i-1]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=2*n;j++){
            dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long res=0;
        for(int j=1;j<=2*n;j++){
            res^=j*dp[i][j];
        }
        res+=i;
        ans^=res;
    }
    cout<<ans<<'\n';
}