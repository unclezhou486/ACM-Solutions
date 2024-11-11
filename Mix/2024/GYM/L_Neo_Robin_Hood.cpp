#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n;

struct node{
    int m,p;
}a[N];

int maxm[N],minp[N];

bool cmp(node a,node b){
    return a.m+a.p>b.m+b.p;
}

bool check(int x){
    priority_queue<int,vector<int>,less<int> > q2;
    priority_queue<int,vector<int>,greater<int> > q1;
    int res=0;
    for(int i=1;i<=x;i++){
        q1.push(a[i].m);
        res+=a[i].m;
        maxm[i]=res;
    }
    for(int i=x+1;i<=n;i++){
        if(q1.size()&&a[i].m>q1.top()){
            res-=q1.top();q1.pop();
            res+=a[i].m;q1.push(a[i].m);
        }
        maxm[i]=res;
    }
    res=0;
    for(int i=n;i>=(n-x+1);i--){
        q2.push(a[i].p);
        res+=a[i].p;
        minp[i]=res;
    }
    for(int i=(n-x);i>=1;i--){
        if(q2.size()&&a[i].p<q2.top()){
            res-=q2.top();q2.pop();
            res+=a[i].p;q2.push(a[i].p);
        }
        minp[i]=res;
    }
    minp[n+1]=1e18;
    for(int i=x;i<=(n-x);i++){
        if(maxm[i]>=minp[i+1]) return 1;
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].m;
    for(int i=1;i<=n;i++) cin>>a[i].p;
    sort(a+1,a+1+n,cmp);
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
}