#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m;

int l[20],r[20];

int b[N];

//bool v[20];
int ans;

void dfs(int pos,int x){
    //v[pos]=x;
    if(x) b[l[pos]]++,b[r[pos]+1]--;
    else b[l[pos]]--,b[r[pos]+1]++;
    if(pos==m){
        int res=0;
        bool flag=1;
        for(int i=1;i<=n;i++){
            res+=b[i];
            //cout<<b[i]<<' ';
            if(res<2){
                flag=0;
                //break;
            }
        }
        //cout<<'\n';
        if(flag) ans++;
        return;
    }
    dfs(pos+1,1);dfs(pos+1,0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    l[0]=0,r[0]=-1;
    dfs(0,0);
    cout<<ans<<'\n';
}