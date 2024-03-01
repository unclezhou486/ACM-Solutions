#include <bits/stdc++.h>

using namespace std;

int n;
void solve(){
    cin>>n;
    int x=0;
    for(int i=1;i<n;i++){
        cout<<"? "<<x<<' '<<x<<' '<<i<<' '<<i<<endl;
        char c;
        cin>>c;
        if(c=='<') x=i;
    }
    vector<int> vec;
    int xx=x;
    vec.push_back(xx);
    for(int i=0;i<n;i++){
        if(i==x) continue;
        cout<<"? "<<x<<' '<<xx<<' '<<x<<' '<<i<<endl;
        char c;
        cin>>c;
        if(c=='<') vec.clear();
        if(c!='>'){
            vec.push_back(i);
            xx=i;
        }
    }
    int xxx=xx;
    for(auto v:vec){
        cout<<"? "<<xxx<<' '<<xxx<<' '<<v<<' '<<v<<endl;
        char c;
        cin>>c;
        if(c=='>') xxx=v;
    }
    cout<<"! "<<x<<' '<<xxx<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    //scanf("%d",&t);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}