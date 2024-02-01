#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;
int n;
int a[N];
struct node{
    int x,id;
}b[N];
//int b[N];

int c[N];

int lowbit(int x){
    return x&(-x);
}

void add(int k,int x){for(;k<=n;k+=lowbit(k))c[k]+=x;}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)) res+=c[x];
    return res;
}

bool cmp(node a,node b){
    if(a.x==b.x) return a.id<b.id;
    else return a.x<b.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i].x=a[i],b[i].id=i;
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        a[b[i].id]=i;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        add(a[i],1);
        ans=max(ans,query(n)-query(i));
        
    }
    cout<<ans<<'\n';
}