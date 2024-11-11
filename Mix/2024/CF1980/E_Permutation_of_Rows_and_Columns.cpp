#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> >  a((n+1),vector<int>(m+1)),b((n+1),vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    map<vector<int>,int> ma;
    for(int i=1;i<=n;i++){
        vector<int> res;
        for(int j=1;j<=m;j++){
            res.push_back(a[i][j]);
        }
        sort(res.begin(),res.end());
        ma[res]++;
    }
    for(int i=1;i<=n;i++){
        vector<int> res;
        for(int j=1;j<=m;j++){
            res.push_back(b[i][j]);
        }
        sort(res.begin(),res.end());
        if(!ma[res]) {cout<<"NO\n";return;}
        ma[res]--;
    }
    for(int i=1;i<=m;i++){
        vector<int> res;
        for(int j=1;j<=n;j++){
            res.push_back(a[j][i]);
        }
        sort(res.begin(),res.end());
        ma[res]++;
    }
    for(int i=1;i<=m;i++){
        vector<int> res;
        for(int j=1;j<=n;j++){
            res.push_back(b[j][i]);
        }
        sort(res.begin(),res.end());
        if(!ma[res]) {cout<<"NO\n";return;}
        ma[res]--;
    }
    cout<<"YES\n";
    return;
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