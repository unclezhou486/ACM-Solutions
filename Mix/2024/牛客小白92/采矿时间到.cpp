#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

char a[10][N];


int n,h;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>h;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int num1=0,num2=0;
    for(int i=1;i<=n;i++){
        if(a[2][i]=='*'){
            num1++;
            if(a[1][i]=='*') num1++;
        }
        else{
            if(a[1][i]=='*') num2++;
        }
        //if(a[4][i]=='*') num1++;
        //if(a[1][i]=='*') num2++;
        if(a[4][i]=='*'){
            num1++;
            if(a[5][i]=='*') num1++;
        }
        else if(a[5][i]=='*') num2++;
    }
    if(num1>=h){
        cout<<h<<'\n';
        return 0;
    }
    int ans=num1;
    h-=num1;
    if(num2*2<=h){
        ans+=num2;
        cout<<ans<<'\n';
        return 0;
    }
    ans+=h/2;
    cout<<ans<<'\n';
}