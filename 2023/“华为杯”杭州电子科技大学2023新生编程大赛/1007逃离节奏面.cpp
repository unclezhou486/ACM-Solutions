#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N=1e3+10;

int t;
int n,m,k;

int d[N][N][5];
char c[N][N][5];
bool vis[N][N][5];
int ansx,ansy;
int h;
int dy[3]={-1,0,1};
void solve(){
    cin>>n>>m>>k;
    //memset(d,0x3f,sizeof d);
    //memset(v)
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++){
                cin>>c[j][f][i];
                d[j][f][i]=1e9;
                vis[j][f][i]=0;
            }
        }
    }
    cin>>h>>ansx>>ansy;
    queue<pair<pair<int,int>,int>> q;
    d[n][m][0]=0;
    vis[n][m][0]=1;
    q.push({{n,m},0});
    while(q.size()){
        pair<pair<int,int>,int> ver=q.front();
        q.pop();
        int xx=ver.first.first,yy=ver.first.second,kk=ver.second;
        int kkk=(kk+1)%k;
        if(xx==n||c[xx+1][yy][kk]=='*'){
            for(int i=0;i<=min(h,xx);i++){
                if(xx-i<=0) break;
                if(c[xx-i][yy][kk]=='*') break;
                for(int ii=0;ii<3;ii++){
                    int yyy=yy+dy[ii];
                    if(yyy<1||yyy>m) continue;
                    if(c[xx-i][yyy][kk]!='*'&&c[xx-i][yyy][kkk]!='*'&&!vis[xx-i][yyy][kkk]){
                        d[xx-i][yyy][kkk]=d[xx][yy][kk]+1;
                        vis[xx-i][yyy][kkk]=1;
                        q.push({{xx-i,yyy},kkk});
                    }
                }
            }
        }
        else{
            for(int ii=0;ii<3;ii++){
                    int yyy=yy+dy[ii];
                    if(yyy<1||yyy>m) continue;
                    //if(c[xx+1][yy][kk]=='*')
                    if(c[xx+1][yyy][kk]!='*'&&c[xx+1][yyy][kkk]!='*'&&!vis[xx+1][yyy][kkk]){
                        d[xx+1][yyy][kkk]=d[xx][yy][kk]+1;
                        vis[xx+1][yyy][kkk]=1;
                        q.push({{xx+1,yyy},kkk});
                    }
                }
        }
    }
    bool fl=0;
    int ans=1e9;
    for(int i=0;i<k;i++){
        if(vis[ansx][ansy][i]){
            fl=1;
            ans=min(d[ansx][ansy][i],ans);
        }
    }
    //cout<<d[2][2][1]<<' '<<d[1][3][1]<<'\n';
    //cout<<d[2][2][0]<<' '<<d[3][1][1]<<' '<<d[3][2][0]<<'\n';
    if(ans==0) ans=1;
    cout<<(fl?ans:-1)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}