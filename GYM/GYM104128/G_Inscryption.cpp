#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int cnt0=0,cnt1=1,sum=1;
    int res0=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        if(x==1){
            cnt1++;
        }
        else if(x==0){
            cnt0++;
        }
        else{
            if(cnt1==1){
                if(cnt0) cnt0--,cnt1++,res0++;
            }
            if(cnt1<2){
                cout<<-1<<'\n';
                return;
            }
            cnt1--;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==0&&res0){
            res0--,a[i]=1;
        }
    }
    sum=1,cnt1=1;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cnt1++;
            sum++;
        }
        else if(a[i]==-1){
            if(cnt1==1) sum++,cnt1++;
            else{
                cnt1--;
            }
        }
        else{
            if(cnt1==1){
                sum++;
                cnt1++;
            }
            else{
                cnt1--;
            }
        }
    }
    int gd=gcd(sum,cnt1);
    cout<<sum/gd<<' '<<cnt1/gd<<'\n';
    return;
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