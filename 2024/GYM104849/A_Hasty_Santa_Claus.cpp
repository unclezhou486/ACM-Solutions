#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,k;

int l[N],r[N];
int ans[N];

priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int kk=k;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    for(int i=1;i<=31;i++){
        for(int j=1;j<=n;j++){
            if(l[j]==i){
                q.push({r[j],j});
            }
        }
        k=kk;
        while(k--&&q.size()){
            ans[q.top().second]=i;
            q.pop();
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}