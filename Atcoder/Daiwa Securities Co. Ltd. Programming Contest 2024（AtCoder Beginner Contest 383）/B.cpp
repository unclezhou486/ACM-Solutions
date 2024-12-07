#include <bits/stdc++.h>

using namespace std;

void solve(){
    int h,w,d;
    cin>>h>>w>>d;
    vector<vector<int> > a(h+10,vector<int>(w+10));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char ch;
            cin>>ch;
            if(ch=='.') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=h;i++){
        for(int  j=1;j<=w;j++){
            if(!a[i][j]) continue;
            for(int k=1;k<=h;k++){
                for(int l=1;l<=w;l++){
                    if(!a[k][l]) continue;
                    int res=0;
                    for(int q=1;q<=h;q++){
                        for(int z=1;z<=w;z++){
                            if(a[q][z]&&(abs(q-i)+abs(z-j)<=d||abs(q-k)+abs(z-l)<=d)){
                                res+=1;
                            }
                        }
                    }
                    ans=max(ans,res);
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    solve();
    return 0;
}