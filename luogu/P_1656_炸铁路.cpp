#include <bits/stdc++.h>

using namespace std;
const int N=5e3+10;
int n,m;
struct node{
    int u,v;
}a[N];
int f[N];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

vector<pair<int,int> > ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v;
    }
    for(int i=1;i<=m;i++){

        for(int j=1;j<=n;j++) f[j]=j;
        for(int j=1;j<=m;j++){
            if(j==i) continue;
            f[find(a[j].u)]=find(a[j].v);
        }
        int fa=find(1);
        bool fl=1;
        for(int i=1;i<=n;i++){
            if(find(i)!=fa){
                fl=0;
                break;
            }
        }
        if(!fl){
            ans.push_back({min(a[i].u,a[i].v),max(a[i].u,a[i].v)});
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}