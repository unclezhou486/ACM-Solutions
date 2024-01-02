#include <bits/stdc++.h>

using namespace std;

const int N=5e4+10;

int t;
int n,c;
int a[N];
int b[N];
//bitset<50010> dp;
bool check(int x){
    //bitset<50010> dp;
    for(int i=1;i<=c;i++){
        if(!b[i]) continue;
        bitset<510> dp;
        for(int j=1;j<=c;j++){
            dp[j]=0;
        }
        dp[0]=1;
        for(int j=i;j<=min(c,i+x);j++){
            if(b[j]){
                int res=0;
                int cnt=1;
                int numm=b[j];
                while(cnt<=numm){
                    dp=dp|(dp<<(cnt*j));
                    numm-=cnt;
                    cnt<<=1;
                }
                if(numm){
                    dp=dp|(dp<<(numm*j));
                }
                //for(int k=1;res<b[j];k<<=1){
                //    if((b[j]>>cnt)&1){
                //        dp=dp|(dp<<(j*k));
                //        res+=k;
                //    }
                //    cnt++;
                //}
            }
            //dp=dp|(dp<<b[j]);
        }
        if(dp[c]) return 1;
    }
    return 0;
}

int main(){
    //freopen("1.out","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=1;i<=c;i++){
            b[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        //sort(a+1,a+1+n);
        int l=0,r=c;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        if(check(l)){
            cout<<l<<'\n';
        }
        else cout<<-1<<'\n';
    }
}