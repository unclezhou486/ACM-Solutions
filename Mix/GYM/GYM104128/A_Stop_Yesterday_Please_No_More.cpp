#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    string str;
    cin>>str;
    int lx=1,ly=1,rx=n,ry=m;
    int _lx=lx,_ly=ly,_rx=rx,_ry=ry;
    for(auto x:str){
        if(x=='U') _lx++,_rx++;
        else if(x=='D') _lx--,_rx--;
        else if(x=='L') _ly++,_ry++;
        else _ly--,_ry--;
        lx=max(lx,_lx);
        rx=min(rx,_rx);
        ly=max(ly,_ly);
        ry=min(ry,_ry);
    }
    vector<vector<int> > pre((n+5),vector<int>(m+5));
    map<pair<int,int>,int > ma;
    auto add = [&] (int x,int y,int xx,int yy) -> void {
        if(ma.count({x,y})) return;
        ma[{x,y}]=1;
        pre[x][y]+=1;
        pre[x][yy+1]-=1;
        pre[xx+1][y]-=1;
        pre[xx+1][yy+1]+=1;
    };
    int res=(ry-ly+1)*(rx-lx+1);
    if(ly>ry||lx>rx) res=0;
    if(lx<=rx&&ly<=ry){
        add(lx,ly,rx,ry);
        for(auto x:str){
            if(x=='U') lx--,rx--;
            else if(x=='D') lx++,rx++;
            else if(x=='L') ly--,ry--;
            else ly++,ry++;
            add(lx,ly,rx,ry);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            if(pre[i][j]==res-k) ans++;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}