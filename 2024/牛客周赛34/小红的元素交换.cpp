#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,a[N];
int b[N];
bool v[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int all=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='R') b[i]=1;
        else b[i]=2;
        all|=b[i];
        if(a[i]==i) cnt++;
    }
    if(all!=3&&cnt!=n){
        cout<<-1<<'\n';
        return 0;
    }
    int ans=0;
    int red=0,white=0;
    for(int i=1;i<=n;i++){
        if(v[i]||i==a[i]) continue;
        v[i]=1;
        int res=0;
        int state=b[i];
        int x=a[i];
        while(x!=i){
            v[x]=1;
            state|=b[x];
            res++;
            x=a[x];
        }
        if(state==3){
            ans+=res;
        }
        else{
            ans+=res+2;
            if(state==1){
                red++;
            }
            else white++;
        }
    }
    cout<<ans-min(white,red)*2<<'\n';
}