 #include <bits/stdc++.h>

 using namespace std;

const int N=1e5+10;
const int mod=1e9+7;

int n,m;
long long a[N],s[N];

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    a[0]=1;
    s[0]=1;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]*a[i],s[i]%=mod;
    //for(int i=1;i<=n;i++){
        //cout<<s[i]<<' ';
    //}
    //cout<<'\n';
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<s[r]*qmi(s[l-1],mod-2)%mod<<'\n';
    }
}