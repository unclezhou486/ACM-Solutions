#include <bits/stdc++.h>

using namespace std;

const int mod=998244353;

void solve(){
    int n;
    cin>>n;
    vector<pair<long long ,long long > > a(4);
    for(int i=1;i<4;i++) a[i]={-1e18,0};
    a[0]={0,1};
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        long long max1=-1,max2=1,min1=-1,min2=1;//1 +,2 -
        long long max1t=0,max2t=0,min1t=0,min2t=0;
        for(int i=0;i<4;i++){
            if(a[i].first==-1e18) continue;
            long long y=a[i].first+x;
            if(y>=0){
                if(max1==-1) max1=y,max1t=a[i].second;
                else{
                    if(max1==y){
                        max1t+=a[i].second;
                        max1t%=mod;
                    }
                    else if(max1<y){
                        max1=y;
                        max1t=a[i].second;
                    }
                }
                if(min1==-1){
                    if(y!=max1) min1=y,min1t=a[i].second;
                }
                else{
                    if(min1==y){
                        min1t+=a[i].second;
                        min1t%=mod;
                    }
                    else if(min1>y){
                        min1=y;
                        min1t=a[i].second;
                    }
                }
            }
            else{
                if(max2==1) max2=y,max2t=a[i].second;
                else{
                    if(max2==y){
                        max2t+=a[i].second;
                        max2t%=mod;
                    }
                    else if(max2<y){
                        max2=y;
                        max2t=a[i].second;
                    }
                }
                if(min2==1){
                    if(y!=max2) min2=y,min2t=a[i].second;
                }
                else{
                    if(min2==y){
                        min2t+=a[i].second;
                        min2t%=mod;
                    }
                    else if(min2>y){
                        min2=y;
                        min2t=a[i].second;
                    }
                }
            }
            y=std::abs(a[i].first+x);
            if(y>=0){
                if(max1==-1) max1=y,max1t=a[i].second;
                else{
                    if(max1==y){
                        max1t+=a[i].second;
                        max1t%=mod;
                    }
                    else if(max1<y){
                        max1=y;
                        max1t=a[i].second;
                    }
                }
                if(min1==-1){
                    if(y!=max1) min1=y,min1t=a[i].second;
                }
                else{
                    if(min1==y){
                        min1t+=a[i].second;
                        min1t%=mod;
                    }
                    else if(min1>y){
                        min1=y;
                        min1t=a[i].second;
                    }
                }
            }
            else{
                if(max2==1) max2=y,max2t=a[i].second;
                else{
                    if(max2==y){
                        max2t+=a[i].second;
                        max2t%=mod;
                    }
                    else if(max2<y){
                        max2=y;
                        max2t=a[i].second;
                    }
                }
                if(min2==1){
                    if(y!=max2) min2=y,min2t=a[i].second;
                }
                else{
                    if(min2==y){
                        min2t+=a[i].second;
                        min2t%=mod;
                    }
                    else if(min2>y){
                        min2=y;
                        min2t=a[i].second;
                    }
                }
            }
        }
        a[0]={max1,max1t};if(max1==-1) a[0].first=-1e18;
        a[1]={min1,min1t};if(min1==-1) a[1].first=-1e18;
        a[2]={max2,max2t};if(max2==1) a[2].first=-1e18;
        a[3]={min2,min2t};if(min2==1) a[3].first=-1e18;
    //        cout<<"FUC:\n";
    //for(int i=0;i<4;i++){
    //    cout<<a[i].first<<' '<<a[i].second<<'\n';
    //}
    }
    //cout<<"CCF:\n";
    //for(int i=0;i<4;i++){
    //    cout<<a[i].first<<' '<<a[i].second<<'\n';
    //}
    cout<<max({a[0],a[1],a[2],a[3]}).second<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}