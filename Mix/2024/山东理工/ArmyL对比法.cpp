#include <bits/stdc++.h>

using namespace std;

int n;

int a[N],b[N];

int main(){
    cin>>n;
    int maxn1=0,minn2=1e4;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn1=max(maxn1,a[i]);
    }
    bool fl=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]>=b[i]) fl=1;
        minn2=min(minn2,b[i]);
    }
    if(fl){
        cout<<"WinWinWin!!!";
    }
    else{
        if(maxn1>=minn2){
            cout<<"HaHa";
        }
        else{
            cout<<"AreYouOK?";
        }
    }
}