#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<char> a(n+10);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[1]='(';
    stack<int> st;
    for(int i=n;i>=1;i--){
        if(a[i]=='('){
            st.pop();
        }
        else if(a[i]==')'){
            st.push(i);
        }
        else{
            a[i]=')';
            st.push(i);
        }
    }
    while(st.size()){
        a[st.top()]='(';
        st.pop();
        if(!st.size()) break;
        st.pop();
    }
    long long  l,r;
    l=r=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='('){
            l+=i;
        }
        else{
            r+=i;
        }
    }
    cout<<r-l<<'\n';
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