#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int a,b,n;

int w[N][N];
int maxn1[N][N],maxn2[N][N];
int minn1[N][N],minn2[N][N];
deque<int> q1,q2;
int ans;
void solve(){
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cin>>w[i][j];
        }
    }
    for(int i=1;i<=a;i++){
        q1.clear();
        q1.push_back(b+1);
        for(int j=b;j>=1;j--){
            while(q1.size()&&q1.front()>j+n-1) q1.pop_front();
            if(q1.size())maxn1[i][j]=max(w[i][q1.front()],w[i][j]);
            while(q1.size()&&w[i][q1.back()]<=w[i][j]) q1.pop_back();
            q1.push_back(j);
        }
        q2.clear();
        q2.push_back(b+1);
        for(int j=b;j>=1;j--){
            while(q2.size()&&q2.front()>j+n-1) q2.pop_front();
            if(q2.size()) minn1[i][j]=min(w[i][q2.front()],w[i][j]);
            while(q2.size()&&w[i][q2.back()]>=w[i][j]) q2.pop_back();
            q2.push_back(j);
        }
    }
    for(int j=1;j<=b;j++){
        q1.clear();
        q1.push_back(a+1);
        for(int i=a;i>=1;i--){ 
            while(q1.size()&&q1.front()>i+n-1) q1.pop_front();
            if(q1.size()) maxn2[i][j]=max(maxn1[i][j],maxn1[q1.front()][j]);
            while(q1.size()&&maxn1[q1.back()][j]<=maxn1[i][j]) q1.pop_back();
            q1.push_back(i);
        }
        q2.clear();
        q2.push_back(a+1);
        for(int i=a;i>=1;i--){ 
            while(q2.size()&&q2.front()>i+n-1) q2.pop_front();
            if(q2.size()) minn2[i][j]=min(minn1[i][j],minn1[q2.front()][j]);
            while(q2.size()&&minn1[q2.back()][j]>=minn1[i][j]) q2.pop_back();
            q2.push_back(i);
        }
    }
    int ans=2e9;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            //cout<<maxn2[i][j]<<' ';
            if(i+n-1>a||j+n-1>b) break;
            ans=min(maxn2[i][j]-minn2[i][j],ans);
        }
        //cout<<'\n';
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}