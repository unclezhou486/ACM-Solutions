#include <bits/stdc++.h>

using namespace std;

int n,m;

//int cnt;
map<string,int> a;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        int x;
        cin>>str>>x;
        a[str]=x;
    }
    cin>>m;
    int ans=0;
    for(int i=1;i<=m;i++){
        string str;
        cin>>str;
        a[str]--;
        if(!a[str]) ans++;
    }
    cout<<ans<<'\n';
}