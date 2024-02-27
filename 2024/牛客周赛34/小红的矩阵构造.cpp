#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,m,x;
int a[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>x;
    if(x%4==0){
        a[1][1]=a[1][2]=a[2][1]=a[2][2]=x/4;
    }
    else if(x>2){
        a[1][1]=a[1][2]=a[2][1]=a[2][2]=(x-6)/4;
        a[2][3]=a[2][4]=a[3][2]=a[3][3]=a[4][2]=a[4][4]=1;
    }
    else{
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}