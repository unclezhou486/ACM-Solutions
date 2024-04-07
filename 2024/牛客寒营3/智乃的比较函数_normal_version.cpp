#include <bits/stdc++.h>

using namespace std;

const int N=60;

pair<pair<int,int>,int> a[N];

//bool check(int )

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[i]={{x,y},z};
    }
    auto check = [&](vector<int> vec) -> bool {
        for(int i=1;i<=n;i++){
            pair<int,int> pos=a[i].first;
            int x=pos.first,y=pos.second;
            int z=a[i].second;
            if((vec[x-1]<vec[y-1])!=z) return 0; 
        }
        return 1;
    };
    bool flag=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                vector<int> vec;
                vec.push_back(i);
                vec.push_back(j);
                vec.push_back(k);
                if(check(vec)) {flag=1;break;}
            }
        }
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
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