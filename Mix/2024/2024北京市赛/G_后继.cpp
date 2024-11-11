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
const int N=4e5+5;
const int MOD=998244353;
const int INF=1e18;
const int C=500;
vector<int>v[35];
int tr[N<<6][2],sum[N<<6],rt=1,tot=1,bh[N<<6];
int d[35],kk[35];
void add(int x,int z){
    int p=rt;
    sum[p]++;
    for(int i=32;i>=0;i--){
        int t=(x>>i)&1;
        if(!tr[p][t])tr[p][t]=++tot;
        if(tr[p][1]&&tr[p][0])d[i]=p;
        p=tr[p][t];
        sum[p]++;
    }
    bh[p]=z;
}
int getmax(int p,int k){
    for(int i=k-1;i>0;i--){
        if(tr[p][1^kk[i]])p=tr[p][1^kk[i]];
        else p=tr[p][kk[i]];
    }
    return bh[p];
}
int getmin(int p,int k){
    for(int i=k-1;i>0;i--){
        if(tr[p][kk[i]])p=tr[p][kk[i]];
        else p=tr[p][1^kk[i]];
    }
    return bh[p];
}
int n,m;
int ask(int p){
    int res;
    cout<<"? "<<p<<endl;
    cin>>res;
    return res;
}
void ans(int x){
    cout<<"! "<<x<<endl;
}
int a[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],add(a[i],i);
    while(m--){
        int as=0;
        for(int i=1;i<=30;i++)kk[i]=0;
        for(int i=1,z=1;i<=30;i++,z*=2){
            if(!d[i-1])continue;
            int b1=getmax(tr[d[i-1]][0],i),b2=getmin(tr[d[i-1]][1],i);
            if(ask(b1)!=b2)kk[i]=1,as+=z;
        }
        ans(as);
    }

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
}