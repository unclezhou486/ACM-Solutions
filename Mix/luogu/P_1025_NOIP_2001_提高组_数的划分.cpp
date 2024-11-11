#include <bits/stdc++.h>

using namespace std;

int n,k,cnt;

void dfs(int la,int sum,int num){
    if(num==k){
        if(sum==n) cnt++;
        return ;
    }
    for(int i=la;i+sum<=n;i++){
        dfs(i,sum+i,num+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    dfs(1,0,0);
    cout<<cnt<<'\n';
}