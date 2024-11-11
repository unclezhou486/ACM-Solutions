#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n;

int a[3][N];
bool v[N*2];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool check(int x,int y){
    if(x<1||x>2||y<1||y>n) return 0;
    return 1;
}

void solve(){
    cin>>n;
    vector<vector<int> > ne(8*n);
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='>') a[i][j]=1;
            else a[i][j]=0;
            v[(i-1)*n+j-1]=0;
        }
    }
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(check(x,y)){
                    //cout<<x<<' '<<y<<'\n';
                    if(a[x][y]) y++;
                    else y--;
                    //cout<<i<<' '<<j<<' '<<x<<' '<<y<<'\n';
                    //cout<<(i-1)*n+j-1<<' '<<(x-1)*n+y-1<<'\n';
                    ne[(i-1)*n+j-1].push_back((x-1)*n+(y-1));
                }
            }
        }
    }
    ne[n-1].push_back(2*n-1);
    ne[2*n-2].push_back(2*n-1);
    queue<int> q;
    q.push(0);
    while(q.size()){
        int x=q.front();
        q.pop();
        if(v[x]) continue;
        v[x]=1;
        for(auto ver:ne[x]){
            //if(x==2) cout<<ver<<'\n';
            if(v[ver]) continue;
            q.push(ver);
        }
    }
    //for(auto ver:ne[2]){
    //    cout<<ver<<' ';
    //}
    //cout<<'\n';
    //for(int i=1;i<=2;i++){
    //    for(int j=1;j<=n;j++){
    //        cout<<v[(i-1)*n+j-1]<<' ';
    //    }
    //    cout<<'\n';
    //}
    if(v[2*n-1]) cout<<"YES\n";
    else cout<<"NO\n";
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