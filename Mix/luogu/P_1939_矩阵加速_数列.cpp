#include <bits/stdc++.h>
#define int long long
using namespace std;
const int m=1e9+7;

int n;


struct mat{
    long long a[4][4];
    mat(){memset(a,0,sizeof a);}
    mat operator*(const mat& T) const {
        mat res;
        for(int i=1;i<=3;i++){
            for(int k=1;k<=3;k++){
                for(int j=1;j<=3;j++){
                    res.a[i][j]=res.a[i][j]+a[i][k]*T.a[k][j],res.a[i][j]%=m;
                }
            }
        }
        return res;
    }
};

mat qmi(mat a,long long b){
    mat res;
    for(int i=1;i<=3;i++){
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
    int t;
    cin>>t;
    while(t--){
    mat A,B;
    cin>>n;
    A.a[1][1]=1;
    A.a[3][1]=1;
    A.a[1][2]=1;
    A.a[2][3]=1;
    B.a[1][1]=1;
    B.a[1][2]=1;
    B.a[1][3]=1;
    A=qmi(A,n-1);
    B=B*A;
    cout<<B.a[1][3]<<'\n';
    }
    
}