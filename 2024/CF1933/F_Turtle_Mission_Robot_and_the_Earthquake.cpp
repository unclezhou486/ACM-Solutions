#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,m;
int a[N][N];

struct node{
    int x,y,t;
};

int dx[2]={0,1};
int dy[2]={1,0};

bool check(int x,int y,int t){
    t%=n;
    if(a[(x+n+t)%n][y]) return 0;
    else return 1;
}

void bfs(){
    //cout<<"fuc";
    int ans=1e9;
    map<pair<pair<int,int>,int>,int> ma;
    queue<node> q;
    q.push({0,0,0});
    while(q.size()){
        node ver=q.front();
        auto [x,y,dis]=ver;
        q.pop();
        if(y==m-1){
            ans=min(ans,dis+(min((n-1-x),x+1)));
            continue;
        }
        if(ma[{{x,y},dis%n}]) continue;
        ma[{{x,y},dis%n}]=1;
        for(int i=0;i<2;i++){
            int xx=(x+dx[i]+n)%n;
            int yy=y+dy[i];
            if(yy>=m||yy<0) continue;
            if(check(xx,yy,dis+1)){
                if(dx[i]==1){
                    if(check(xx,yy,dis)){
                        q.push({xx,yy,dis+1});
                    }
                }
                else{
                    q.push({xx,yy,dis+1});
                }
            }
        }
    }
    ma.clear();
    //cout<<"f";
    if(ans==1e9)cout<<-1<<'\n';
    else cout<<ans<<'\n';
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    bfs();
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