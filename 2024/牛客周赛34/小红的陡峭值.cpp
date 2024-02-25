#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
int a[N];

map<int,int> ma;
int cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int st=-1,ed=-1;
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        st=a[i];break;
    }
    for(int i=n;i>=1;i--){
        if(!a[i]) continue;
        ed=a[i];break;
    }
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        if(!ma[a[i]]) cnt++;
        ma[a[i]]+=1;
    }
    if(st==-1){
        for(int i=1;i<n;i++){
            cout<<1<<' ';
        }
        cout<<2<<'\n';
    }
    else{
        if(st==ed&&cnt==1){
            if(a[1]){
                if(a[n]==0){
                    for(int i=1;i<n;i++) cout<<st<<' ';
                    cout<<st+1<<'\n';
                }
                else{
                    cout<<-1<<'\n';
                }
            }
            else{
                if(a[n]==0){
                    for(int i=1;i<n;i++){
                        cout<<st<<' ';
                    }
                    cout<<st+1<<'\n';
                }
                else{
                    cout<<st+1<<' ';
                    for(int i=1;i<n;i++){
                        cout<<st<<' ';
                    }
                }
            }
        }
        else if(st==ed&&cnt>1){
            cout<<-1<<'\n';
        }
        else{
            if(cnt>2){
                cout<<-1<<'\n';
            }
            else if(st==ed+1){
                int res=st;
                for(int i=1;i<=n;i++){
                    if(a[i])res=min(res,a[i]);
                    cout<<res<<' ';
                    
                }
            }
            else if(st+1==ed){
                int res=st;
                for(int i=1;i<=n;i++){
                    if(a[i]) res=max(res,a[i]);
                    cout<<res<<' ';
                }
            }
            else{
                cout<<-1<<'\n';
            }
        }
    }
}