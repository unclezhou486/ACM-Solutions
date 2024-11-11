#include <bits/stdc++.h>

using namespace std;

int n,m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    vector<vector<int> > a(n+1,vector<int> (m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int k=30;k>=0;k--){
        vector<vector<int> > vis(n+1,vector<int> (m+1));
        int tmp=ans|(1<<k);
        queue<pair<int,int> > q;
        if((a[1][1]&tmp)==tmp)q.push({1,1}),vis[1][1]=1;
        while(q.size()){
            pair<int,int> pos=q.front();
            int x=pos.first,y=pos.second;
            q.pop();
            //if(vis[x][y]) continue;
            //vis[x][y]=1;
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx>0&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&((a[xx][yy]&tmp)==tmp)){
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }
        if(vis[n][m]) ans=tmp;
    }
    cout<<ans<<'\n';
}