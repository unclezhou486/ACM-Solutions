#include <bits/stdc++.h>

using namespace std;

int a[4][4];

void solve(){
    char ch;
    cin>>ch;
    if(ch=='<') a[1][2]=0,a[2][1]=1;
    else a[1][2]=1,a[2][1]=0;
    cin>>ch;
    if(ch=='<') a[1][3]=0,a[3][1]=1;
    else a[1][3]=1,a[3][1]=0;
    cin>>ch;
    if(ch=='<') a[2][3]=0,a[3][2]=1;
    else a[2][3]=1,a[3][2]=0;
    for(int i=1;i<=3;i++){
        int res=0;
        for(int j=1;j<=3;j++){
            if(j==i) continue;
            res+=a[i][j];
        }
        if(res==1){
            cout<<char('A'+i-1)<<'\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}