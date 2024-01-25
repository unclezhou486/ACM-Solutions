#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,m;
int a[N][N];
bool v[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool check(int x,int y){
    if(a[x][y]||x<1||x>n||y<1||y>m) return 1;
    else return 0;
}

vector<pair<int,int> > bfs(int i,int j){
    queue<pair<int,int> > q;
    vector<pair<int,int> > res;
    //for(int ii=1;ii<=n;ii++){
    //    for(int jj=1;jj<=m;jj++){
    //        v[ii][jj]=0;
    //    }
    //}
    q.push({0,0});
    res.push_back({0,0});
    v[i][j]=1;
    while(q.size()){
        pair<int,int> pos=q.front();
        q.pop();
        for(int w=0;w<4;w++){
            int xx=pos.first+i+dx[w],yy=pos.second+j+dy[w];
            if(check(xx,yy)||v[xx][yy]) continue;
            q.push({pos.first+dx[w],pos.second+dy[w]});
            v[xx][yy]=1;
            res.push_back({pos.first+dx[w],pos.second+dy[w]});
        }
    }
    return res;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j)||v[i][j]) continue;
            vector<pair<int,int> > res;
            res=bfs(i,j);
            //if(i==1&&j==1){
            //    for(int q=0;q<res.size();q++){
            //        cout<<res[q].first<<' '<<res[q].second<<'\n';
            //    }
            //}
            bool fl=1;
            for(int ii=1;ii<=n;ii++){
                //if(!fl) break;
                for(int jj=1;jj<=m;jj++){
                    //cout<<'f'<<ii<<' '<<jj<<'\n';
                    if(!fl) break;
                    if(ii==i&&jj==j) continue;
                    //cout<<'u'<<ii<<' '<<jj<<'\n';
                    if(check(ii,jj)) continue;
                    //cout<<'c'<<ii<<' '<<jj<<'\n';
                    bool fll=0;
                    //cout<<ii<<' '<<jj<<'\n';
                    for(int q=0;q<res.size();q++){
                        int dxx=res[q].first,dyy=res[q].second;
                        //cout<<i<<' '<<j<<' '<<ii+dxx<<' '<<jj+dyy<<'\n';
                        if(check(ii+dxx,jj+dyy)){
                            fll=1;
                            break;
                        }
                    }
                    if(!fll){
                        fl=0;
                    }
                }
            }
            if(fl)ans+=res.size();
        }
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v[i][j]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
1 3
.O.

*/