#include <bits/stdc++.h>

using namespace std;
const int N=(1<<10)+7;

int d[N];
int n,m;
int a[110][20];

int bfs(int st){
    d[st]=1;
    queue<int> q;
    q.push(st);
    while(q.size()){
        int x=q.front();
        q.pop();
        for(int i=1;i<=m;i++){
            int res=x;
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    if((x>>j)&1){
                        res-=(1<<j);
                    }
                }
                else if(a[i][j]==-1){
                    if(!((x>>j)&1)){
                        res+=(1<<j);
                    }
                }
            }
            if(!d[res]) d[res]=d[x]+1,q.push(res);
        }
    }
    if(d[0]) return d[0]-1;
    else return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int st=0;
    for(int i=0;i<n;i++){
        st+=(1<<i);
    }
    cout<<bfs(st)<<'\n';

}