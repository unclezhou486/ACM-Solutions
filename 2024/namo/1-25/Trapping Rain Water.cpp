#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,q;
    cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    vector<int>len1(n+2);
    vector<int>len2(n+2);
    vector<int>val1(n+2);
    vector<int>val2(n+2);
    set<int> s1,s2;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i],ans-=a[i],b[n-i+1]=a[i];
    //cout<<1<<'\n';
    s1.insert(0),s1.insert(n+1);
    val1[n+1]=1e18;
    //cout<<2<<'\n';
    s2.insert(0),s2.insert(n+1);
    val2[n+1]=1e18;
    //s1.insert({{0,0},0});s2.insert({{0,0},0});
    //s1.insert({{n+1,0},1e18});s2.insert({{n+1,0},1e18});
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
    //cout<<3<<'\n';
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
    //cout<<ans-maxnn*n<<'\n';
    cin>>q;
    while(q--){
        int x,v,y;
        cin>>x>>v;
        y=n-x+1;
        a[x]+=v;
        b[y]+=v;
        maxnn=max(a[x],maxnn);
        ans-=v;
        auto it=s1.upper_bound(x);
        it--;
        //cout<<"Case:\n";
        //cout<<ans<<' '<<*it<<'\n';
        if(val1[*it]<a[x]){
            int ll=*it;
            int lenn=len1[*it];
            int vall=val1[*it];
            //cout<<ans<<'\n'; 
            ans-=lenn*vall;
            //cout<<ans<<'\n';
            //cout<<ans<<'\n';
            it++;
            vector<set<int>::iterator> vec;
            while(val1[*it]<=a[x]){
                ans-=len1[*it]*val1[*it];
                //cout<<ans<<'\n';
                vec.push_back(it);
                it++;
            }
            it--;
            int rr=*it+len1[*it]-1;
            for(int i=0;i<vec.size();i++){
                s1.erase(vec[i]);
            }
            //cout<<*it<<'\n';
            
            //cout<<rr<<'\n';
            s1.insert(x);
            len1[x]=rr-x+1;
            val1[x]=a[x];
            ans+=len1[x]*val1[x];
            if(ll<x){
                len1[ll]=x-ll;
                ans+=len1[ll]*val1[ll];
            }
            //cout<<ans<<'\n';
        }
        it=s2.upper_bound(y);
        it--;
        //cout<<ans<<'\n';
        if(val2[*it]<b[y]){
            int  ll=*it;
            int lenn=len2[*it];
            int vall=val2[*it];
            ans-=lenn*vall;

            //cout<<ans<<'\n';
            it++;
            vector<set<int>::iterator> vec;
            while(val2[*it]<=b[y]){
                ans-=len2[*it]*val2[*it];
                //cout<<ans<<'\n';
                vec.push_back(it);
                it++;
            }
            it--;
            int rr=*it+len2[*it]-1;
            for(int i=0;i<vec.size();i++){
                s2.erase(vec[i]);
            }
            
            s2.insert(y);
            len2[y]=rr-y+1;
            val2[y]=b[y];
            ans+=len2[y]*val2[y];
                        if(ll<y){
                len2[ll]=y-ll;
                ans+=len2[ll]*val2[ll];
            }
            //cout<<ans<<'\n';
        }        
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
/*
1
5
100 10 1 10 100
1
3 100
*/