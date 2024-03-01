#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

char a[3][N];
int dx[2]={0,1};
int dy[2]={1,0};

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    string ans="";
    int res1=0,res2=0;
    res1=1;
    ans+=a[1][1];
    for(int i=2;i<=n;i++){
        if(res1==-1){
            ans+=a[2][i-1];
            continue;
        }
        char x=min(a[1][i],a[2][i-1]);
        ans+=x;
        if(res1!=-1&&a[1][i]==x&&a[2][i-1]!=x){
            res2=0;
        }
        else if(a[1][i]!=x&&a[2][i-1]==x){
            res2+=res1;
            res1=-1;
        }
        else if(res1!=-1){
            res2++;
        }
    }
    cout<<ans+a[2][n]<<'\n';
    if(res1!=-1) res2+=res1; 
    cout<<res2<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}