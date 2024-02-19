#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,k;

int a[N];

int s[N];
int r[N];
map<int,int> ma;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    ma[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]+s[i-1];
        s[i]%=k;
        if(ma.count(s[i])){
            r[ma[s[i]]]=i;
        }
        ma[s[i]]=i;
        //cout<<s[i]<<' ';
    }
    //cout<<'\n';
    //cout<<r[0]<<'\n';
    int ans=0;
    int rr=-1;
    for(int i=0;i<=n;i++){
        if(i>=rr&&r[i]){
            ans++;
            rr=r[i];
        }
        if(r[i]&&r[i]<rr){
            rr=r[i];
        }
        //cout<<i<<' '<<rr<<' '<<ans<<'\n';
    }
    cout<<ans<<'\n';
}