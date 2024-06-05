#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int> ma;
    vector<int> a(n+5);
    vector<vector<int> > bitr(n+5,vector<int>(32)),bitl(n+5,vector<int>(32));
    vector<int> maxl(n+5),maxr(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<pair<int,int> > st;
    st.push({2e9,0});

    for(int i=1;i<=n;i++){
        while(st.size()&&st.top().first<=a[i]){
            st.pop();
        }
        maxl[i]=st.top().second;
        st.push({a[i],i});
    }
    while(st.size())st.pop();
    st.push({2e9,n+1});
    for(int i=n;i>=1;i--){
        while(st.size()&&st.top().first<=a[i]){
            st.pop();
        }
        maxr[i]=st.top().second;
        st.push({a[i],i});
    }
    for(int i=0;i<32;i++){
        bitl[0][i]=0;
        bitr[n+1][i]=n+1;
        for(int j=1;j<=n;j++){
            if((a[j]>>i)&1){
                bitl[j][i]=j;
            }
            else{
                bitl[j][i]=bitl[j-1][i];
            }
        }
        for(int j=n;j>=1;j--){
            if((a[j]>>i)&1){
                bitr[j][i]=j;
            }
            else{
                bitr[j][i]=bitr[j+1][i];
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        int l=0,r=n+1;
        for(int j=0;j<32;j++){
            if((a[i]>>j)&1) continue;
            else{
                l=max(l,bitl[i][j]);
                r=min(r,bitr[i][j]);
            }
        }
        long long res=(long long)(i-maxl[i])*(maxr[i]-i);
        int ll=max(l,maxl[i]);
        int rr=min(r,maxr[i]);
        ll=max(ll,ma[a[i]]);
        ma[a[i]]=i;
        ans+=(long long)(i-ll)*(rr-i);
        //cout<<i<<' '<<res<<'\n';
        //cout<<"pre:"<<ans<<'\n';
        //if(l>maxl[i]){
            //ans+=(maxr[i]-i)*(l-maxl[i]);
        //}
        //if(r<maxr[i]){
            //ans+=(i-maxl[i])*(maxr[i]-r);
        //}
        //cout<<maxl[i]<<' '<<maxr[i]<<' '<<l<<' '<<r<<'\n';
        //cout<<"suf:"<<ans<<'\n';
    }
    ans=(long long)n*(n+1)/2-ans;
    cout<<ans<<'\n';
}

signed main(){
    //freopen("1.in","r",stdin);
    //freopen("2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//void solve(){
//    int n;
//    cin>>n;
//    vector<int> a(n+5),maxl(n+5),maxr(n+5);
//    vector<vector<int> > dpor(n+5,vector<int>(20)),dpto(n+5,vector<int>(20)),dpmax(n+5,vector<int>(20));
//    for(int i=1;i<=n;i++){
//        cin>>a[i];
//        dpor[i][0]=a[i];
//        dpto[i][0]=i+1;
//        dpmax[i][0]=a[i];
//    }
//    dpto[n+1][0]=n+1;
//    for(int i=1;i<20;i++){
//        dpto[n+1][i]=n+1;
//        for(int j=1;j<=n;j++){
//            dpto[j][i]=dpto[dpto[j][i-1]][i-1];
//            dpor[j][i]=(dpor[j][i-1]|dpor[dpto[j][i-1]][i-1]);
//            dpmax[j][i]=max(dpmax[j][i-1],dpmax[dpto[j][i-1]][i-1]);
//        }
//
//    }
//    stack<pair<int,int> >st;
//    st.push({2e9,0});
//    for(int i=1;i<=n;i++){
//        while(st.size()&&st.top().first<=a[i]) st.pop();
//        maxl[i]=st.top().second;
//        st.push({a[i],i});
//    }
//    while(st.size()) st.pop();
//    st.push({2e9,n+1});
//    for(int i=n;i>=1;i--){
//        while(st.size()&&st.top().first<=a[i]) st.pop();
//        maxr[i]=st.top().second;
//        st.push({a[i],i});
//    }
//    long long ans=0;
//    for(int i=1;i<=n;i++){
//        int res=i;
//        //int res2=res;
//        int res1=a[i];
//        int res3=a[i];
//        for(int t=1;t<=32;t++){
//            if(res==n+1) break;
//            int res2=res;
//            for(int j=19;j>=0;j--){
//                if((res1|dpor[res][j])==res1){
//                    //cout<<"pre:"<<res<<' ';
//                    res=dpto[res][j];
//                    //cout<<"suf:"<<res<<'\n';
//                }
//            }
//            //cout<<res<<'\n';
//            //return;
//            //res=dpto[res][0];
//            if(res!=n+1){    
//                //int ress=res;
//                res1|=a[res];
//                int ress=res,ress1=res1;
//                for(int j=19;j>=0;j--){
//                    if((res1|dpor[res][j])==res1){
//                        res=dpto[res][j];
//                    }
//                }
//                res1|=a[res];
//                for(int j=19;j>=0;j--){
//                    if(max(dpmax[res2][j],res3)<ress1){
//                        res2=dpto[res2][j];
//                        res3=max(dpmax[res2][j],res3);
//                    }
//                }
//                res3=max(res3,a[res2]);
//                ans+=res2-ress;
//                cout<<i<<' '<<ress<<' '<<res2<<' '<<res<<'\n';
//                //res=dpto[res][0];
//            }
//        }
//        //cout<<ans<<'\n';
//    }
//    cout<<ans<<'\n';
//}
//
//int main(){
//    //freopen("1.in","r",stdin);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    solve();
//    return 0;
//}
//


/*


*/


/*
#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+5);
    vector<vector<int> > dpmax(n+5,vector<int>(20)),dpor(n+5,vector<int>(20)),dpto(n+5,vector<int>(20));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dpmax[i][0]=a[i];
        dpor[i][0]=a[i];
        dpto[i][0]=i+1;
    }
    dpto[n+1][0]=n+1;
    for(int i=1;i<20;i++){
        dpto[n+1][i]=n+1;
        for(int j=1;j<=n;j++){
            dpto[j][i]=dpto[dpto[j][i-1]][i-1];
            dpmax[j][i]=max(dpmax[j][i-1],dpmax[dpto[j][i-1]][i-1]);
            dpor[j][i]=(dpor[j][i-1]|dpor[dpto[j][i-1]][i-1]);
        }
    }
    auto prin = [&] (int x,int y) -> void {
        cout<<dpmax[x][y]<<' '<<dpor[x][y]<<' '<<dpto[x][y]<<'\n';
    };
    //prin(833,1);
    //prin(835,0);
    //return ;
    //cout<<dpmax[833][1]<<' '<<dpor[833][1]<<' '<<dpto[833][0];

    long long ans=0;
    for(int i=1;i<=n;i++){
        int res=i;
        int res1=a[i],res2=a[i];
        for(int j=19;~j;j--){
            if(max(dpmax[res][j],res1)>=(dpor[res][j]|res2)){
                //if(i==833){
                //    cout<<"CCF:\n";
                //    prin(res,j);
                //    cout<<res<<' '<<res1<<' '<<res2<<'\n';
                //}
                res1=max(res1,dpmax[res][j]);
                res2|=dpor[res][j];
                res=dpto[res][j];
                //if(i==833){
                //    cout<<"FUC:\n";
                //    prin(res,j);
                //    cout<<res<<' '<<res1<<' '<<res2<<'\n';
                //}
            } 
        }
        if(res!=n+1) cout<<i<<' '<<res<<'\n';
        ans+=(n-res+1);
    }
    //cout<<ans<<'\n'; 
}

int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}


*/