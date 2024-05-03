#include <bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;

const int N=1e5+10;

int n,a[N];
int qian;

struct node{
    int dp[N];
}res1,res2,res3;

void Getmin(int hp,node &b){
    priority_queue<PII> q;
    b=res3;
    for(int i=1;i<=n;i++){
        if(a[i]) q.push({a[i],2});
        hp-=a[i];
        int res=0;
        while(q.size()&&hp<=0){
            PII pos=q.top();
            q.pop();
            hp+=pos.first;
            res++;
            pos.second-=1;
            if(pos.second) q.push(pos);
        }
        if(hp<=0) break;
        b.dp[i]=res+b.dp[i-1];
    }
    return;
}

bool check(int x){
    Getmin(x,res1);
    reverse(a+1,a+1+n);
    Getmin(x,res2);
    reverse(res2.dp+1,res2.dp+1+n);
    for(int i=1;i<=n;i++){
        int res=res1.dp[i]+res2.dp[i];
        if(res1.dp[i]>res1.dp[i-1]&&res2.dp[i]>res2.dp[i+1]) res--;
        if(res<=qian) return 1;
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    qian=n/2;
    int l=1,r=0;//l can't be zero ,because hp must > 0
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res3.dp[i]=1e18;
        r+=a[i];
    }
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
}