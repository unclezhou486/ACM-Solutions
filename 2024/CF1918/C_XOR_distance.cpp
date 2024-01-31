#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

void solve(){
    long long a,b,r;
    cin>>a>>b>>r;
    long long cnt=0;
    long long res=0;
    long long rr=r;
    int k=0;
    for(int i=0;i<=61;i++){
        if(!rr){
            k=i;
            break;
        }
        rr>>=1;
    }
    bool fl=1;
    for(int i=61;i>=0;i--){
        int aa=(a>>i)&1;
        int bb=(b>>i)&1;
        if(aa!=bb){
            if(res+(1ll<<i)>r){
                long long c=aa-bb;
                cnt+=(c*((abs(c))<<i));
            }
            else{
                if(cnt==0){
                    long long c=aa-bb;
                    cnt+=(c*(abs(c))<<i);
                }
                else if(cnt<0){
                    if(bb){
                        if(cnt!=0)res+=(1ll<<i);
                        cnt+=(1ll<<i);
                    }
                    else{
                        cnt+=(1ll<<i);
                    }
                }
                else{
                    if(aa){
                        cnt-=(1ll<<i),res+=(1ll<<i);
                    }
                    else cnt-=(1ll<<i);
                }
                //cnt+=(1ll<<i),res+=(1ll<<i);
                //else cnt-=(1ll<<i);
            }
        }
        //cout<<cnt<<' '<<res<<'\n';
    }
    cout<<abs(cnt)<<'\n';
}
/*
1
9 6 10
*/

int main(){
    //cout<<(1ll<<61)<<'\n';
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}