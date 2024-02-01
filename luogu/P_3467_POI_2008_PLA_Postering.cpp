#include <bits/stdc++.h>

using namespace std;
const int N=3e5+10;
int n;
int a[N];
stack<int> st;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(st.empty()){
            ans++;
            st.push(a[i]);
        }
        else{
            while(st.size()&&st.top()>a[i]){
                st.pop();
            }
            if(st.size()&&st.top()==a[i]) continue;
            else{
                st.push(a[i]);
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}