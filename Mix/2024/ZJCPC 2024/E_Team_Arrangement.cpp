#include <bits/stdc++.h>


using namespace std;

const int N=70;

int n;

struct node{
    int l,r;
}a[N];

int b[N],cnt[N];
int ans=-1e9;
int w[N];

//int 

bool cmp(node a,node b){
    return a.l<b.l;
}

long long lowbit(long long x){
    return x&(-x);
}

map<long long,int> ma;

void dfs(int pos,int res,int idx){
    b[idx]=pos;
    if(!res){
        int ll=1;
        bool fla=1;
        //priority_queue<int,vector<int>,greater<int> > q;//r
        long long sum=0;
        for(int i=1;i<=60;i++) cnt[i]=0;
        for(int i=1;i<=idx;i++){
            for(ll;ll<=n;ll++){
                if(a[ll].l>b[i]) break;
                //q.push(a[ll].r);
                sum|=(1ll<<a[ll].r);
                cnt[a[ll].r]++;
            }
            //int xx=b[idx];
            for(int j=1;j<=b[i];j++){
                //if(q.size()&&q.top()>=b[i]) q.pop();
                int summ=ma[lowbit(sum)];
                if(sum&&summ>=b[i]){
                    cnt[summ]--;
                    if(!cnt[summ]) sum-=lowbit(sum);
                } 
                else {fla=0;break;}
            }
            //ll=ll+b[i];
            if(!fla) break;
        }
        if(fla){
            int ress=0;
            //cout<<"CCF:";
            for(int i=1;i<=idx;i++){
                //cout<<b[i]<<' ';
                ress+=w[b[i]];
            }
            //cout<<'\n';
            ans=max(ress,ans);
        }
        return;
    }
    for(int i=pos;i<=res;i++){
        if(res-i>=i||!(res-i))dfs(i,res-i,idx+1);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<=60;i++){
        ma[(1ll<<i)]=i;
    }
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
    for(int i=1;i<=n;i++) cin>>w[i];
    sort(a+1,a+1+n,cmp);
    dfs(1,n,0);
    if(ans==-1e9) cout<<"impossible\n";
    else cout<<ans<<'\n';
}