#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e3+10;

int n,m;
int h[N];
int ans;
int l[N],r[N];

void solve1(){
    stack<int> st;
    st.push(0);
    for(int i=1;i<=m;i++){
        while(st.size()&&h[st.top()]>h[i]) st.pop();
        l[i]=st.top();
        st.push(i);
    }
}

void solve2(){
    stack<int> st;
    st.push(m+1);
    for(int i=m;i>=1;i--){
        while(st.size()&&h[st.top()]>=h[i]) st.pop();
        r[i]=st.top();
        st.push(i);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    m=n;
    h[0]=h[m+1]=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='W') h[j]++;
            else h[j]=0;
        }
        solve1(),solve2();
        for(int j=1;j<=m;j++){
            ans+=(r[j]-j)*(j-l[j])*h[j];
        }
    }
    cout<<ans<<'\n';
}