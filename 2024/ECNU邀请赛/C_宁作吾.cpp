#pragma GCC O(2)
#pragma GCC O(3)
#include <bits/stdc++.h>
#define int long long
using namespace std;

//void solve(){
    //int n,l,r;
    //cin>>n>>l>>r;
    //vector<int> a(n);
    //for(int i=0;i<n;i++) cin>>a[i];
    //sort(a.begin(),a.end());
    //long long ans=1e18;
    //auto dfs = [&] (auto self,vector<int> &vec,long long res) -> void {
    //    if(res>=ans) return;
    //    if(vec.size()==1){
    //        ans=min(ans,res);
    //        return;
    //    }
    //    for(int i=r;i>=l;i--){
    //        if(vec.size()<i) continue;
    //        vector<int> vecc;
    //        long long ress=0;
    //        for(int j=0;j<i;j++){
    //            ress+=vec[j];
    //        }
    //        //vecc.push_back(ress);
    //        bool flag=0;
    //        for(int j=i;j<vec.size();j++){
    //            if(flag||vec[j]<ress){
    //                vecc.push_back(vec[j]);
    //            }
    //            else{
    //                flag=1;
    //                vecc.push_back(ress);
    //                vecc.push_back(vec[j]);
    //            }
    //        }
    //        if(!flag) vecc.push_back(ress);
    //        //sort(vecc.begin(),vecc.end());
    //        self(self,vecc,res+ress);
    //    }
    //};
    //dfs(dfs,a,0);
    //if(ans!=1e18)cout<<ans<<'\n';
    //else cout<<-1<<'\n';
//}

struct node{
    vector<int> vec;
    int res;
};

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<node> dp(n);
    for(int i=0;i<n;i++) dp[i].res=1e18;
    dp[n-1].vec=a;
    dp[n-1].res=0;
    queue<int> q;
    vector<int> vis(n);
    q.push(n-1);
    while(q.size()){
        int x=q.front();
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=r;i>=l;i--){
            if(i>dp[x].vec.size()) continue;
            int res=0;
            for(int j=0;j<i;j++){
                res+=dp[x].vec[j];
            }
            vector<int> vecc;
            bool flag=0;
            for(int j=i;j<dp[x].vec.size();j++){
                if(flag||dp[x].vec[j]<res){
                    vecc.push_back(dp[x].vec[j]);
                }
                else{
                    flag=1;
                    vecc.push_back(res);
                    vecc.push_back(dp[x].vec[j]);
                }
            }
            if(!flag) vecc.push_back(res);
            if(res+dp[x].res<dp[x-i+1].res){
                dp[x-i+1].vec=vecc;
                dp[x-i+1].res=dp[x].res+res;
                q.push(x-i+1);
            }
        }
    }
    if(dp[0].res!=1e18)cout<<dp[0].res<<'\n';
    else cout<<-1<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
