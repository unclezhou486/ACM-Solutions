#include <bits/stdc++.h>

using namespace std;

long double n,k;

long double d,s;

int main(){
    cin>>n>>k>>d>>s;
    long double ans=(n*d-k*s);
    ans/=(n-k);
    if(ans<0||ans>100){
        cout<<"impossible\n";
    }
    else cout<<fixed<<setprecision(7)<<ans<<'\n';
}