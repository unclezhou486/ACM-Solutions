#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

char c[N];

void solve(){
    int n;
    char ch;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]=='p'){
            if(i>2){
                if(c[i-2]=='m'&&c[i-1]=='a'){
                    ans++;
                    c[i]=' ';
                    continue;
                }
            }
        }
        else if(c[i]=='e'){
            if(i>2){
                if(c[i-2]=='p'&&c[i-1]=='i'){
                    ans++;
                }
            }
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
