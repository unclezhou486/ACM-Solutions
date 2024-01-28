#include <bits/stdc++.h>
#define int long long
#define IT set<int>::iterator
using namespace std;

void solve(){
    int n,q;
    cin>>n;
    vector<int>a(n+1);vector<int>b(n+1);
    vector<int>len1(n+2);vector<int>len2(n+2);
    vector<int>val1(n+2);vector<int>val2(n+2);
    set<int> s1,s2;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i],ans-=a[i],b[n-i+1]=a[i];
    s1.insert(0),s1.insert(n+1);val1[n+1]=1e18;
    s2.insert(0),s2.insert(n+1);val2[n+1]=1e18;
    int maxn=a[1];
    int maxnn=a[1];
    ans+=maxn;
    int l=1;
    for(int i=2;i<=n;i++){
        maxnn=max(maxnn,a[i]);
        if(a[i]>maxn){
            s1.insert(l);
            len1[l]=i-l;
            val1[l]=maxn;
            maxn=a[i];
            l=i;
        }
        ans+=maxn;
    }
    s1.insert(l);
    len1[l]=n+1-l;
    val1[l]=maxn;
    maxn=b[1];
    ans+=maxn;
    l=1;
    for(int i=2;i<=n;i++){
        if(b[i]>maxn){
            s2.insert(l);
            len2[l]=i-l;
            val2[l]=maxn;
            maxn=b[i];
            l=i;
        }
        ans+=maxn;
    }
    s2.insert(l);
    len2[l]=n+1-l;
    val2[l]=maxn;
    cin>>q;
    while(q--){
        int x,v,y;
        cin>>x>>v;
        y=n-x+1;
        a[x]+=v;
        b[y]+=v;
        maxnn=max(a[x],maxnn);
        ans-=v;
        auto change=[](vector<int> &a,vector<int> &len,vector<int> &val,set<int> &s,int &x,int &ans){
            auto it=s.upper_bound(x);
            it--;
            if(val[*it]>=a[x]) return;
            int ll=*it;
            int lenn=len[*it];
            int vall=val[*it];
            ans-=lenn*vall;
            it++;
            IT itl,itr;
            itl=it;
            itr=it;
            while(val[*it]<=a[x]){
                ans-=len[*it]*val[*it];
                it++;
                itr=it;
            }
            it--;
            int rr=*it+len[*it]-1;
            s.erase(itl,itr);
            s.insert(x);
            len[x]=rr-x+1;
            val[x]=a[x];
            ans+=len[x]*val[x];
            if(ll<x){
                len[ll]=x-ll;
                ans+=len[ll]*val[ll];
            }
        };
        change(a,len1,val1,s1,x,ans);
        change(b,len2,val2,s2,y,ans);
        cout<<ans-maxnn*n<<'\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}