#pragma GCC O(2)
#pragma GCC O(3)
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    long long x,y;
};

long long det(node a,node b){
    return a.x*b.y-a.y*b.x;
}

bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

void solve(){
    int n;
    cin>>n;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int cnt=0;
    map<pair<int,int>,int> ma;
    vector<vector<node> > vec(n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //node res={a[j].x-a[i].x,a[j].y-a[i].y};
            int xx=(a[j].x+a[i].x),yy=(a[j].y+a[i].y);
            if(ma.count({xx,yy})){
                vec[ma[{xx,yy}]].push_back({a[i].x*2-xx,a[i].y*2-yy});
            }
            else{
                ma[{xx,yy}]=++cnt;
                vec[cnt].push_back({a[i].x*2-xx,a[i].y*2-yy});
            }
        }
    }
    long long ans=0;
    for(auto [c,d]:ma){
        for(int i=0;i<vec[d].size();i++){
            for(int j=i+1;j<vec[d].size();j++){
                ans=max(ans,abs(det(vec[d][i],vec[d][j])));
            }
        }
    }
    if(!ans) cout<<"-1\n";
    else cout<<ans/2<<".0\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}