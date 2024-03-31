#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,a[N];

void solve(){
    int x,n,y;
    cin>>x>>n>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=a[1]+x;
    int ans=n-2;
    vector<int> vec1,vec2;
    for(int i=2;i<=n+1;i++){
        int res=a[i]-a[i-1];
        if(a[i]-a[i-1]==2) ans++;
        if(a[i]-a[i-1]>2){
            if(res%2){
                vec1.push_back(res/2);
            }
            else{
                vec2.push_back(res/2-1);
            }
        }
    }
    sort(vec2.begin(),vec2.end());
    for(auto v:vec2){
        if(!y) break;
        //cout<<v<<' '<<y<<'\n';
        if(y>=v){
            ans+=(v*2+1);
            y-=v;
        }
        else{
            ans+=(y*2);
            y=0;
        }
    }
    for(auto v:vec1){
        if(!y) break;
        //cout<<v<<' '<<y<<'\n';
        if(y>=v){
            ans+=(2*v);
            y-=v;
        }
        else{
            ans+=y*2;
            y=0;
        }
    }
    cout<<ans<<'\n';
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