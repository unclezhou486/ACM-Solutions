#include <bits/stdc++.h>

using namespace std;

const int N=510;

int n;

long long len[N];

string str[3]={""," COFFEE"," CHICKEN"};

void answer(long long x,int n){
    //cout<<x<<' '<<n<<'\n';
    while(n>2){
        if(!len[n-2]||x<=len[n-2]) n-=2;
        else x-=len[n-2],n-=1;
    }
    cout<<str[n][x];
    return;
}

void solve(){
    cin>>n;
    for(int i=3;i<=n;i++){
        if(len[i-1]&&len[i-2])len[i]=len[i-1]+len[i-2];
        if(len[i]>1e17) len[i]=0;
    }
    //cout<<len[100]<<'\n';
    long long k;
    cin>>k;
    long long kk=k+9;
    if(len[n])kk=min(len[n],kk);
    for(long long i=k;i<=kk;i++){
        answer(i,n);
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //cin>>n;
    len[1]=6;len[2]=7;
    //for(int i=1;i<=n;i++)
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}