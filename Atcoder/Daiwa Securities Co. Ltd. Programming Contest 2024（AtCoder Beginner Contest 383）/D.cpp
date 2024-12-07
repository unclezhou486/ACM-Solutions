#include <bits/stdc++.h>

using namespace std;
 
constexpr int N=2e6+10;

 vector<int> son[N];
bool vis[N];

void init(){
    for(int i=2;i<N;i++){
        if(vis[i]) continue;
        for(int j=i;j<N;j+=i){
            vis[j]=1;
            son[j].push_back(i);
        }
    }
}

bool check(long long x){
    long long res=0;
    for(long long i=1;i<=x/i;i++){
        if(x%i==0){
            if(x==i*i) res+=1;
            else res+=2;
        }
    }
    if(res==4) return 1;
    else return 0;
}

void solve(){
    long long n;
    cin>>n;
    long long ans=0;
    for(long long i=1;i*i<=n;i++){
        if((son[i].size()==2&&son[i][0]*son[i][1]==i)||(son[i].size()==1&&1ll*son[i][0]*son[i][0]*son[i][0]*son[i][0]==i)) ans++;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t=1;
    solve();
    return 0;
}