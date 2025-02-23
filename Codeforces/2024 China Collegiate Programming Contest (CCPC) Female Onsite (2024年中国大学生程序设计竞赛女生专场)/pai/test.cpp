#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> a(n+10);
    vector<int> ans(61,2);
    // vector<vector<vector<long long> > > dp(61,vector<vector<long long> > (2,vector<long long>(2) ) ) ;//idx digit limit
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=60;j>=0;j--){
            int resx=(a[i]>>j)&1;
            int resy=(a[i-1]>>j)&1;
            if(resx!=resy){
                if(resx>resy){
                    if(ans[j]==2){
                        ans[j]=0;
                    }
                    else if(ans[j]!=0){
                        cout<<0<<'\n';
                        return;
                    }
                }
                else{
                    if(ans[j]==2){
                        ans[j]=1;
                    }
                    else if(ans[j]!=1){
                        cout<<0<<'\n';
                        return;
                    }
                }
                break;
            }
        }
    }
    vector<int> c(63);
    for(int j=60;j>=0;j--){
        if((k>>j)&1) c[j]=1;
        else c[j]=0;
    }
    vector<vector<long long> > dp(63,vector<long long>(10,-1));
    auto dfs= [&] (auto self,int pos,long long pre,bool limit) -> long long{
        if(pos==-1) return 1;
        if(pre>=0&&!limit&&dp[pos][pre]!=-1)return dp[pos][pre];
        int b=(limit?c[pos]:1);
        long long anss=0;
        for(int i=0;i<=b;i++){
            if(ans[pos]==1&&i==0) continue;
            if(ans[pos]==0&&i==1) continue;
            anss+=self(self,pos-1,i,i==b&&limit);
        }
        if(!limit&&pos) dp[pos][pre]=anss;
        return anss;
    };
    cout<<dfs(dfs,61,0,1)<<'\n';
    // for(int j=60;j>=0;j--){
    //     if((k>>j)&1){
    //         dp[j][1][1]=dp[j][1][]
    //     }
    // }
    // for(int j=60;j>=0;j--){
    //     cout<<ans[j]<<" \n"[j==0];
    // }

    // long long anss=1;
    // for(int j=60;j>=0;j--){
    //     if(ans[j]!=2){
    //         if((ans[j])!=((k>>j)&1)){
    //             anss=0;
    //         }
    //     }
    // }
    // long long res=1;
    // // for(int j=0;j<=60;j++){
    // //     if(((k>>j)&1)&&ans[j]!=1){
    // //         cout<<j<<' '<<res<<'\n';
    // //         anss+=res;

    // //     }
    // //     if(ans[j]==2) res*=2;
    // // }
    // for(int j=0;j<=60;j++){
    //     if(ans[j]==2) res*=2;
    // }
    // bool flag=true;
    // for(int j=60;j>=0;j--){
    //     if(ans[j]==2)res/=2;
    //     if(ans[j]==1&&(1ll<<j)>k){
    //         cout<<0<<'\n';
    //         return;
    //     }
    //     if((k>>j)&1){
    //         if(ans[j]==0){
    //             anss+=res;
    //             break;
    //         }
    //         else if(ans[j]==2){
    //             anss+=res;
    //         }
    //     }
    //     else{
    //         if(ans[j]==1){
    //             if(1ll<<(j+1)>=k){
    //                 anss+=res;
    //                 break;
    //             }
    //             else{
    //                 anss=0;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // cout<<anss<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}