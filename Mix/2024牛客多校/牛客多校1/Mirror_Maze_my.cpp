#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int vis[N][N][5];
bool v[N][N][5];
char a[N][N];
void solve(){
    int n,m;
    cin>>n>>m;
    int dx[5]={0,-1,1,0,0};
    int dy[5]={0,0,0,-1,1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    auto check = [&] (int x,int y) -> bool {
        if(x<1||x>n||y<1||y>m) return 0;
        else return 1;
    };
    auto change = [&] (int x,int y,int z) -> int {
        if(z==1){//above
            if(a[x][y]=='-') z=2;
            else if(a[x][y]=='/') z=4;
            else if(a[x][y]=='\\') z=3;
        }
        else if(z==2){//below
            if(a[x][y]=='-') z=1;
            else if(a[x][y]=='/') z=3;
            else if(a[x][y]=='\\') z=4;
        }
        else if(z==3){//left
            if(a[x][y]=='|') z=4;
            else if(a[x][y]=='/') z=2;
            else if(a[x][y]=='\\') z=1;
        }
        else{
            if(a[x][y]=='|') z=3;
            else if(a[x][y]=='/') z=1;
            else if(a[x][y]=='\\') z=2;
        }
        return z;
    };
    auto trans = [&] (int z) -> int {
        if(z&1) return z+1;
        else return z-1;
    };
    auto dfss = [&] (auto self,int x,int y,int z,int xo,int yo) -> void {
        int zz=z;
        int cnt=0;
        map<pair<int,int>,int> ma;
        queue<pair<pair<int,int>,int> > qu;
        while(check(x,y)&&(x!=xo||y!=yo||zz!=change(x,y,z))){
            vis[x][y][trans(z)]=cnt;
            v[x][y][trans(z)]=1;
            qu.push({{x,y},trans(z)});
            if(z!=change(x,y,z)&&!ma.count({x,y})) cnt++;
            if(z!=change(x,y,z)) ma[{x,y}]+=1;
            z=change(x,y,z);
            x=x+dx[z],y=y+dy[z];
        }
        if(check(x,y)){
            if(change(x,y,z)!=z&&!ma.count({x,y}))cnt++;
            while(qu.size()){
                auto a=qu.front();
                qu.pop();
                vis[a.first.first][a.first.second][a.second]=cnt;
            }
        }
        int zzz=trans(z);
        v[x][y][zzz]=1;
        vis[x][y][zzz]=cnt;
    };
    //above below left right        
    auto dfs = [&] (auto self,int x,int y,int z,int xo,int yo) -> void {
        if(!check(x,y)||(x==xo&&y==yo)){
            z=trans(z);
            dfss(dfss,x+dx[z],y+dy[z],z,x,y);
            return;
        }
        z=change(x,y,z);
        self(self,x+dx[z],y+dy[z],z,xo,yo);
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=4;k++){
                if(!v[i][j][k]){
                    dfs(dfs,i+dx[k],j+dy[k],k,i+dx[k],j+dy[k]);
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x,y,z;
        string op;
        cin>>x>>y>>op;
        if(op[0]=='a') z=1;
        else if(op[0]=='b') z=2;
        else if(op[0]=='l') z=3;
        else z=4;
        cout<<vis[x][y][z]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}