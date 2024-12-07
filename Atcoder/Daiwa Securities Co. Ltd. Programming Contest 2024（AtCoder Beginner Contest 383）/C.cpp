#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solve(){
    int h,w,d;
    cin>>h>>w>>d;
    vector<vector<int> > a(h+10,vector<int>(w+10)),vis(h+10,vector<int>(w+10)),dis(h+10,vector<int>(w+10,1e9));
    int res=0;
    queue<pair<int,int> >q;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char ch;
            cin>>ch;
            if(ch=='.') a[i][j]=1;
            else if(ch=='#') a[i][j]=0;
            else {
                // res++;
                dis[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(q.size()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>0&&xx<=h&&yy>0&&yy<=w&&a[xx][yy]){
                if(dis[xx][yy]>dis[x][y]+1){
                    dis[xx][yy]=dis[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(dis[i][j]<=d){
                res+=1;
            }
        }
    }
    cout<<res<<'\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    solve();
    return 0;
}