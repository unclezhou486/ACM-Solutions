#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
double a[N],b[N];
bool v[N][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+n);
    double ans=0;
    double aa=0,bb=0;
    for(int i=1,j=1;i<=n&&j<=n;){
        aa+=a[i]*(!v[i][0]);
        bb+=b[j]*(!v[j][1]);
        v[i][0]=v[j][1]=1;
        ans=max(ans,min(aa-i-j,bb-i-j));
        if(aa>=bb) j++;
        if(aa<=bb) i++;
        //cout<<aa-i-j<<' '<<bb-i-j<<' '<<i<<' '<<j<<'\n';
    }
    cout<<fixed<<setprecision(4)<<ans<<'\n';
}