#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n;

int a[N];

int b[10];

int c[10];

int d[10];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]<10){
            c[a[i]]++;
        }
    }
    long long ans=0;
    for(int i=1;i<=9;i++){//x+x    
        for(int j=1;j<=9;j++){
            if((i*10+j)%36==0) ans+=c[i]*c[j];
        }
    }
    //c[0]=c[9];
    for(int i=1;i<=n;i++){
        if(a[i]<10) continue;
        int res=0;
        int x=a[i]%10;
        int y=a[i]%9;
        int yy=9-y;
        int yyy=yy;
        if(yy==9) yy=0;
        if(a[i]%4==0){
            ans+=b[yy]+c[yyy];
        }
        if((x*10+yyy)%4==0) ans+=c[yyy];
        ans+=d[yy];
        b[y]++;
        if(a[i]%4==0) d[y]++;
    }
    cout<<ans<<'\n';
}