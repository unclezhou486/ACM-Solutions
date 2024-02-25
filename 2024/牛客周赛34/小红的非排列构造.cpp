#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
int a[N];
bool v[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    bool fl=1;
    int cnt=0;;
    for(int i=1;i<=n;i++){
        int x;
        cin>>a[i];
        x=a[i];
        if(x>n){
            fl=0;break;
        }
        if(!v[x]) cnt++;
        v[x]=1;
    }
    //cout<<cnt<<'\n';
    if(fl&&cnt==n){
        int res=n;
        if(a[1]==n) res=1;
        cout<<1<<'\n';
        cout<<1<<' '<<res<<'\n';
    }
    else cout<<0<<'\n';
}