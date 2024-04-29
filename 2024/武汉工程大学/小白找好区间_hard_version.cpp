#include <bits//stdc++.h>
#define int long long

using namespace std;

const int N=2e5+10;

int n,k;

int a[N];
struct node{
    int x,id;
}s[N];
bool cmp(node a,node b){
    return a.x<b.x;
}

int b[N];

int c[N];

int lowbit(int x){
    return x&(-x);
}

void add(int k,int x){
    for(k;k<=n;k+=lowbit(k)){
        c[k]+=x;
    }
}

int query(int x){
    int res=0;
    for(x;x;x-=lowbit(x)){
        res+=c[x];
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        if(str=="byl") a[i]=1;
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        s[i].x=(k+1)*a[i]-k*i;
        s[i].id=i;
    }
    s[0].id=0;
    s[0].x=0;
    sort(s,s+1+n,cmp);
    int cnt=1;
    b[s[0].id]=cnt;
    for(int i=1;i<=n;i++){
        if(s[i].x!=s[i-1].x) cnt++;
        b[s[i].id]=cnt;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans+=query(b[i]-1);
        add(b[i],1);
    }
    cout<<ans<<'\n';
}