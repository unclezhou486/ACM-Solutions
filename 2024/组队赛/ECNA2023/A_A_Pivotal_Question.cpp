#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n;
int a[N];
int b[N];
int c[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=c[i]=0;
    }
    b[1]=1;
    int maxn=a[1];
    for(int i=2;i<=n;i++){
        maxn=max(maxn,a[i]);
        if(maxn==a[i]){
            b[i]=1;
        }
    }
    c[n]=1;
    int minn=a[n];
    for(int i=n-1;i>=1;i--){
        minn=min(minn,a[i]);
        if(minn==a[i]){
            c[i]=1;
        }
    }
    queue<int >q;
    for(int i=1;i<=n;i++){
        if(b[i]&&c[i]){
            q.push(i);
        }
    }
    cout<<q.size()<<' ';
    vector<int> vec;
    while(q.size()){
        vec.push_back(a[q.front()]);
        if(vec.size()==100) break;
        //cout<<a[q.front()]<<' ';
        q.pop();
    }
    for(auto v:vec){
        cout<<v<<' ';
    }
}