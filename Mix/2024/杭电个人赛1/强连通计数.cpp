#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
const int mod=1e9+7;

int n,a[N];
int p[N];
int d[N];
int ru[N];

int st,ed;

bool v[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],ru[a[i]]++;
    for(int i=1;i<=n;i++) cin>>p[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int y=(1-p[i]+mod)%mod;
        p[i]=y;
        ans+=p[i];
        ans%=mod;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!ru[i]){
            q.push(i);
        }
    }
    while(q.size()){
        int x=q.front();
        q.pop();
        ru[a[x]]--;
        if(!ru[a[x]]) q.push(a[x]);
    }
    vector<int> ve;
    for(int i=1;i<=n;i++){
        if(ru[i]==1) ve.push_back(i);
    }   
    int res=1;
    vector<vector<int> > vec;
    for(auto x:ve){
        if(!v[x]){
            vector<int> vecc;
            int y=x;
            vecc.push_back(y);
            v[y]=1;
            while(a[y]!=x){
                y=a[y];
                v[y]=1;
                vecc.push_back(y);
            }
            vec.push_back(vecc);
        }
    }
    for(auto x:vec){
        int ress=1;
        for(auto y:x){
            ress*=p[y];
            ress%=mod;
        }
        ans-=ress*x.size();
        ans%=mod;
        ans+=mod;
        ans%=mod;
        ans+=ress;
        ans%=mod;
    }
    ans%=mod;
    cout<<ans<<'\n';
}