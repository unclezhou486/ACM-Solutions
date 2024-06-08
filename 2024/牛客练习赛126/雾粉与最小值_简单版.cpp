#include <bits/stdc++.h>

using namespace std;

struct node{
    int id,val,minlen,maxlen;
};
bool cmp(node a,node b){
    return a.val<b.val;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    int m;
    cin>>m;
    vector<node> q(m);
    vector<int> ans(m);
    for(int i=0;i<m;i++){
        q[i].id=i;
        cin>>q[i].val>>q[i].minlen>>q[i].maxlen;
        //cout<<"CCF"<<q[i].val<<' '<<q[i].minlen<<' '<<q[i].maxlen<<'\n';
    }
    sort(q.begin(),q.end(),cmp);
    //for(int i=0;i<m;i++){
        //cout<<"CCF"<<q[i].val<<' '<<q[i].minlen<<' '<<q[i].maxlen<<'\n';        
    //}
    set<int> se;
    se.insert(0);
    se.insert(n+1);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qu;
    for(int i=1;i<=n;i++){
        qu.push({a[i],i});
    }
    map<int,int> ma;
    set<int> see;
    int len=n;
    ma[len]=1;
    see.insert(n);
    for(int i=0;i<m;i++){
        while(qu.size()&&qu.top().first<q[i].val){
            int id=qu.top().second;
            qu.pop();
            auto it=se.lower_bound(id);
            int r=*it;
            it--;
            int l=*it;
            int ress=r-l-1;
            ma[ress]--;
            if(!ma[ress]) see.erase(ress);
            int res1=id-l-1,res2=r-id-1;
            if(!ma[res1]) see.insert(res1);
            if(!ma[res2]) see.insert(res2);
            ma[res1]++;ma[res2]++;
            se.insert(id);
        }
        //cout<<q[i].val<<' '<<q[i]
        auto it=see.end();
        it--;
        //cout<<q[i].val<<' '<<q[i].minlen<<' '<<*it<<'\n';
        ans[q[i].id]=((*it)>=q[i].minlen);
    }
    for(int i=0;i<m;i++){
        if(ans[i]) cout<<"Yes\n";
        else cout<<"No\n";
        //cout<<ans[i]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}