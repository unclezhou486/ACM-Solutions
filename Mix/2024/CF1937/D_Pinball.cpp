#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;

int n;
char s[N];
int a[N];
int sr[N],sl[N];
int ar[N],al[N];
int ans[N];

bool check1(int ll,int rr,int res){ // 
    if(ar[rr]-ar[ll]>=res) return 1;
    else return 0;
}

bool check2(int ll,int rr,int res){
    if(al[rr]-al[ll]>=res) return 1;
    else return 0;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        ans[i]=1e18;
        al[i]=ar[i]=sl[i]=sr[i]=0;
        if(s[i]=='<') {
            al[i]=1;
            sl[i]=i;
        }
        else{
            ar[i]=1;
            sr[i]=i;
        }
        sl[i]+=sl[i-1];
        al[i]+=al[i-1];
        sr[i]+=sr[i-1];
        ar[i]+=ar[i-1];
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='<'){
            int rl=ar[i-1],rr=al[n]-al[i];
            int res=min(rl,rr);
            if(rl==0){
                ans[i]=min(ans[i],i);
                continue;
            }
            if(rl==rr){
                ans[i]=min(ans[i],2*((sl[n]-sl[i])-i*rr)+2*(i*rl-(sr[i-1]))+i);
            }
            else if(rl<rr){
                int lll=i,rrr=n;
                while(lll<rrr){
                    int mid=(lll+rrr)>>1;
                    if(check2(i,mid,rl)) rrr=mid;
                    else lll=mid+1;
                }
                ans[i]=min(ans[i],2*((i*rl-sr[i-1]))+2*(sl[lll]-sl[i]-i*rl)+i);
            }
            else{
                int lll=1,rrr=i;
                while(lll<rrr){
                    int mid=(lll+rrr+1)>>1;
                    if(check1(mid-1,i-1,rr+1)) lll=mid;
                    else rrr=mid-1;
                }
                ans[i]=min(ans[i],2*(sl[n]-sl[i]-i*rr)+2*(i*(rr+1)-(sr[i-1]-sr[lll-1]))+n-i+1);
            }
        }
        else{
            int rl=ar[i-1],rr=al[n]-al[i];
            int res=min(rl,rr);
            if(rr==0){
                ans[i]=min(ans[i],n-i+1);
                continue;
            }
            if(rl==rr){
                ans[i]=min(ans[i],2*(sl[n]-sl[i]-i*rr)+2*(i*rl-sr[i-1])+n-i+1);
            }
            else if(rl<rr){
                int lll=i,rrr=n;
                while(lll<rrr){
                    int mid=(lll+rrr)>>1;
                    if(check2(i,mid,rl+1)) rrr=mid;
                    else lll=mid+1;
                }
                ans[i]=min(ans[i],2*((i*rl-sr[i-1]))+2*(sl[lll]-sl[i]-i*(rl+1))+i);
            }
            else{
                int lll=1,rrr=i;
                while(lll<rrr){
                    int mid=(lll+rrr+1)>>1;
                    if(check1(mid-1,i-1,rr)) lll=mid;
                    else rrr=mid-1;
                }
                ans[i]=min(ans[i],2*(sl[n]-sl[i]-i*rr)+2*(i*(rr)-(sr[i-1]-sr[lll-1]))+n-i+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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