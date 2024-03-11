#include <bits/stdc++.h>

using namespace std;

const int N=110;

int a[N],b[N],c[N];

int n,m,l;

map<int,int> ma;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    cin>>l;
    for(int i=1;i<=l;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=l;k++){
                ma[a[i]+b[j]+c[k]]=1;
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(ma[x]) cout<<"Yes\n";
        else cout<<"No\n";
    }
}