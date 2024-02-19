#include <bits/stdc++.h>
#define PIII pair<pair<int,int>,int>
using namespace std;
const int N=1e5+10;

int n;
int a[N],b[N];
priority_queue<PIII ,vector<PIII > ,greater<PIII> >q;
map<pair<int,int>,int> ma;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    q.push({{a[1]+b[1],1},1});
    while(n--){
        int i=q.top().first.second;
        int j=q.top().second;
        if(ma.count({i,j})){
            n++;
            q.pop();
            continue;
        }
        ma[{i,j}]=1;
        cout<<q.top().first.first<<' ';
        //cout<<i<<' '<<j<<'\n';
        q.push({{a[i+1]+b[j],i+1},j});
        q.push({{a[i]+b[j+1],i},j+1});
        q.pop();
    }
}