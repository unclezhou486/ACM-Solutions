#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

struct node{
    int id[10];
}a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<10;i++){
        a[0].id[i]=i;
    }
    for(int i=1;i<=n;i++){
        int aa,bb;
        a[i]=a[i-1];
        cin>>aa>>bb;
        swap(a[i].id[aa],a[i].id[bb]);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        node tmp,ans;
        for(int i=0;i<10;i++){
            tmp.id[a[r].id[i]]=i;
        }
        for(int i=0;i<10;i++){
            ans.id[tmp.id[a[l-1].id[i]]]=i;
        }
        for(int i=0;i<10;i++){
            cout<<ans.id[i]<<' ';
        }
        cout<<'\n';
    }
}