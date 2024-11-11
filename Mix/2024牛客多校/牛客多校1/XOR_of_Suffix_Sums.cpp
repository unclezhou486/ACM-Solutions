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
const int N=5e5+5;
const int MOD=2097152;
int tr[25][MOD<<1];
int d[25];
int n=MOD;
int lowbit(int x){return x&-x;}
void add(int a[],int x,int k){
    x+=1;
    for(int i=x;i<=n;i+=lowbit(i))a[i]+=k;
}
int find(int a[],int x){
    int ans=0;x+=1;
    for(int i=x;i;i-=lowbit(i))ans+=a[i];
    return ans;
}
int q,len,z;
int sum[N];
void solve(){
    d[0]=1;
    for(z=1;;z++){
        d[z]=d[z-1]*2;
        if(d[z]==MOD){
            z--;
            break;
        }
    }
    // cout<<z<<"\n";
    for(int i=0;i<=z;i++){
        add(tr[i],0,1);
    }
    cin>>q;
    while(q--){
        int t,v;
        cin>>t>>v;
        while(t--){
            for(int i=0;i<=z;i++){
                add(tr[i],sum[len]%d[i+1],-1);
            }
            len--;
        }
        len++;
        sum[len]=sum[len-1]+v;
        for(int i=0;i<=z;i++)add(tr[i],sum[len]%d[i+1],1);
        int ans=0;
        for(int i=0;i<=z;i++){
            int _=sum[len]%d[i+1];
            int num=0;
            if(_-d[i]>=0)num+=find(tr[i],_-d[i]);
            num+=find(tr[i],_+d[i])-find(tr[i],_);
            num%=2;
            ans+=d[i]*num;
        }
        cout<<ans<<"\n";
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
