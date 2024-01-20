#include <bits/stdc++.h>

using namespace std;

int n;
queue<int> q[110];
int main(){
    cin>>n;
    int m=log(n-1)/log(2)+1;
    cout<<m<<'\n';
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m;j++){
            if((i>>j)&1) q[j+1].push(i);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<q[i].size()<<' ';
        while(q[i].size()){
            cout<<q[i].front()<<' ';
            q[i].pop();
        }
        cout<<'\n';
    }
    string s;
    cin>>s;
    int res=0;
    for(int i=m-1;i>=0;i--){
        int d=s[i]-'0';
        res<<=1;
        res+=d;
    }
    if(res==0) cout<<n<<'\n';
    else cout<<res<<'\n';
}