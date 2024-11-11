#include <bits/stdc++.h>

using namespace std;

int n,m,p;

int x,ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>p>>x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int res=x-i*j;
            int y=2*(i+j);
            //cout<<i<<' '<<j<<' '<<res<<' '<<y<<'\n';
            if(res>=y&&res%y==0&&res/y<=p){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}