#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> a(n);
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'||s[i]=='(') a[i]=1;
        else a[i]=2;
        if(st.size()&&st.top()==a[i]) st.pop();
        else{
            st.push(a[i]);
        }
    }
    if(st.empty()){
        bool fl=0;
        for(int i=0;i<n-2;i++){
            if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
                fl=1;break;
            }
        }
        if(fl){
            cout<<"No\n";
        }
        else{
            int cnt=0;
            for(int i=0;i<n-1;i++){
                if(a[i]==a[i+1]) cnt++;
                if(cnt>2){
                    cout<<"No\n";
                    return;
                }
            }
            cout<<"Yes\n";
        }
    }
    else{
        cout<<"Yes\n";
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