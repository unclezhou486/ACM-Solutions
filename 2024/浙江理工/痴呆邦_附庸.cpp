#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+10;
const int mod=998244353;
int a[N];

void solve(){
    int n;
    cin>>n;
    cout<<a[n]<<'\n';
}

int C(int n){
    //if(n==1) return 0;
    return (n-1)*n/2;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    a[1]=1;
    a[2]=1;
    a[3]=2;
    int res=3;
    for(int i=4;i<=1000;i++){
        a[i]=a[i-1];
        for(int j=1;j<=i-1;j++){
            int k=i-1-j;
            if(k<j) break;
            //a[i]+=a[j]*a[k];
            if(j==k){
                a[i]+=(C(a[j]));
                a[i]+=a[j];
            }
            else{
                a[i]+=a[j]*a[k];
            }
            a[i]%=mod;
        }
        a[i]%=mod;
    }
    //for(int i=1;i<=10;i++){
    //    cout<<a[i]<<' ';
    //}
    //cout<<'\n';
    while(t--){
        solve();
    }
    return 0;
}