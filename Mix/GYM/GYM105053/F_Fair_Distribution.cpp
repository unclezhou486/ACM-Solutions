#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<unordered_map>
#define ll long long
#define int long long
using namespace std;
const int N=2e5+5;
const int MOD=998244353;
const int INF=1e18;
const int C=500;
int n;
int a[N],b[N];
bitset<N> dp;
int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
void solve(){
    cin>>n;
    int f=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(!a[i])f=1;
        sum+=a[i];
    }
    int x=b[1];
    for(int i=1;i<=n;i++)x=gcd(x,b[i]);
    vector<int> az;  
    vector<int>num(C+1);
    for(int i=1;i<=n;i++){
        if(a[i]>C)az.push_back(a[i]);
        else num[a[i]]++;
    }
    vector<int>dpa(N);
    dp[0]=1;
    for(int i=0;i<az.size();i++){
        dp|=dp<<az[i];
        //for(int u=2e5;u>=az[i];u--)dpa[u]|=dpa[u-az[i]];
    }
    for(int i=1;i<=C;i++){
        int _=num[i],__=0;
        while(_>=(1ll<<__)){
            int x=i*(1<<__);
            dp|=dp<<x;
            //for(int u=2e5;u>=x;u--)dpa[u]|=dpa[u-x];
            _-=(1ll<<__);
            __++;
        }
        if(_){
            int x=i*_;
            dp|=dp<<x;
            //for(int u=2e5;u>=x;u--)dpa[u]|=dpa[u-x];
        }

    }
    for(int i=0;i<sum;i++){
        if(i==0&&f==0)continue;
        if(dp[i]){
            int _=i,__=sum-i;
            if(_%x==__%x){
                cout<<"Y\n";
                return;
            }

        }
    }
    cout<<"N\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
}
// vector<int>dpa(suma+1);
    // dpa[0]=1;
    // for(int i=0;i<az.size();i++){
    //     for(int i=suma;i>=az[i];i--)dpa[i]|=dpa[i-az[i]];
    // }
    // vector<int>dpb(sumb+1);
    // vector<int>num(C+1);
    // dpb[0]=1;
    // for(int i=0;i<bz.size();i++)num[bz[i]]++;
    // for(int i=1;i<=C;i++){
    //     int _=num[i],__=0;
    //     while(_>=(1<<__)){
    //         int x=i*(1<<__);
    //         for(int i=sumb;i>=x;i--)dpb[i]|=dpb[i-x];
    //         _-=x;
    //         __++;
    //     }
    //     if(_){
    //         int x=i*_;
    //         for(int i=sumb;i>=x;i--)dpb[i]|=dpb[i-x];
    //     }
    // }