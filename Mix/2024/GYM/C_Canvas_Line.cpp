#include <bits/stdc++.h>

using namespace std;

const int N=2e3+10;

int l[N],r[N];
int n,p;
//int a[N];
int x;
int vis[N];
int v[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    cin>>p;
    int st=1;
    while(p--){
        cin>>x;
        if(x<l[st]) continue;
        while(st<=n&&x>r[st]) st++;
        if(x<l[st]) continue;
        if(st<=n){
            vis[st]++;
            v[st]=x;
            if(r[st]==x&&l[st+1]==x){
                st++;
                if(st<=n){
                    vis[st]++;
                    v[st]=x;
                }
            }
        }
    }
    bool fl=1;
    for(int i=1;i<=n;i++){
        if(vis[i]>2){
            fl=0;
            break;
        }
    }
    if(!fl){
        cout<<"impossible\n";
    }
    else{
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(i<n){
                if(vis[i]==2) continue;
                else if(vis[i]==1){
                    if(vis[i+1]==2){
                        if(v[i]==r[i]){
                            q.push(v[i]-1);
                        }
                        else{
                            if(v[i]!=r[i]-1){
                                q.push(r[i]-1);
                            }
                            else{
                                q.push(v[i]-1);
                            }
                        }
                    }
                    else{
                        if(l[i+1]==r[i]){
                            if(v[i]!=r[i]){
                                vis[i+1]++;
                                q.push(r[i]);
                            }
                            else{
                                q.push(r[i]-1);
                            }
                        }
                        else{
                            if(v[i]!=r[i]){
                                q.push(r[i]);
                            }
                            else q.push(r[i]-1);
                        }
                    }
                }
                else{
                    if(vis[i+1]==2){
                        q.push(r[i]-1);
                        q.push(r[i]-2);
                    }
                    else{
                        if(l[i+1]==r[i]){
                            q.push(r[i]);
                            q.push(r[i]-1);
                            vis[i+1]++;
                        }
                        else{
                            q.push(r[i]);
                            q.push(r[i]-1);
                        }
                    }
                }
            }
            else{
                if(vis[i]==2) continue;
                else if(vis[i]==1){
                    if(v[i]==r[i]){
                        q.push(r[i]-1);
                    }
                    else q.push(r[i]);
                }
                else{
                    q.push(r[i]);
                    q.push(r[i]-1);
                }
            }
        }
        cout<<q.size()<<'\n';
        while(q.size()){
            cout<<q.front()<<' ';
            q.pop();
        }
    }
}