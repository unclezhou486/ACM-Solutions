#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,p,q,a1,a2;

struct mat{
    long long a[4][4];
    mat(){memset(a,0,sizeof a);}
    mat operator*(const mat& T) const {
        mat res;
        for(int i=1;i<=2;i++){
            for(int k=1;k<=2;k++){
                for(int j=1;j<=2;j++){
                    res.a[i][j]=res.a[i][j]+a[i][k]*T.a[k][j],res.a[i][j]%=m;
                }
            }
        }
        return res;
    }
}A,B;

mat qmi(mat a,long long b){
    mat res;
    for(int i=1;i<=2;i++){
        res.a[i][i]=1;
    }
    while(b){
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>p>>q>>a1>>a2>>n>>m;
    if(n==1) cout<<a1%m;
    else if(n==2) cout<<a2%m;
    else{
        A.a[1][1]=p;
    A.a[1][2]=1;
    A.a[2][1]=q;
    B.a[1][1]=a2;
    B.a[1][2]=a1;
    A=qmi(A,n-2);
    B=B*A;
        cout<<B.a[1][1]<<'\n';
    }
}