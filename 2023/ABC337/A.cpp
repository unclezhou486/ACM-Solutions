#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int a,b;
    int x,y;
    cin>>n;
    a=b=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a+=x,b+=y;
    }
    if(a>b) cout<<"Takahashi\n";
    else if(a==b) cout<<"Draw\n";
    else cout<<"Aoki\n";
}