#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

struct node{
    int x,v;
}a[N];

struct Node{
    int id,num;
}q[100010];

bool cmp(Node a,Node b){
    return a.num<b.num;
}

int ans[100010];

int dp[100010];

int main(){
    ios::sync_with_stdio();
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int res=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].v;
        res+=a[i].v;
    }
    for(int i=1;i<=res;i++) dp[i]=1e9;
    for(int i=1;i<=n;i++){
        for(int j=res;j>=a[i].v;j--){
            dp[j]=min(dp[j],dp[j-a[i].v]+a[i].x);
        }
    }
    //cout<<dp[2]<<'\n';
    vector<pair<int,int> > vec;
    set<int> se;
    map<int,int> maa;
    for(int j=1;j<=res;j++){
        if(dp[j]!=1e9){
            vec.push_back({dp[j],j});
            se.insert(dp[j]);
            maa[dp[j]]=max(maa[dp[j]],j);
        }
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].num;
        se.insert(q[i].num);
    }
    map<int,int> ma;
    int cnt=0;
    for(auto x:se){
        ma[x]=++cnt;
        //cout<<x<<' ';
    }
    //cout<<'\n';
    vector<int> answ(cnt+1);
    int idx=0;
    for(auto x:se){
        idx++;
        if(maa.count(x)) answ[idx]=maa[x];
        answ[idx]=max(answ[idx-1],answ[idx]);
    }
    for(int i=1;i<=m;i++){
        cout<<answ[ma[q[i].num]]<<'\n';
    }
    //for(int )
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
////int w[N],v[N];
//
//void solve(){
//    int n,m;
//    cin>>n>>m;
//    vector<int> w(n+1),v(n+1);
//    int res=0;
//    for(int i=1;i<=n;i++) cin>>w[i],res+=w[i];
//    for(int i=1;i<=n;i++) cin>>v[i];
//    vector<int> dp(res+1);
//    for(int i=1;i<=n;i++){
//        for(int j=res;j>=w[i];j--){
//            
//        }
//    }
//    
//}
//
//int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    solve();
//    return 0;
//}