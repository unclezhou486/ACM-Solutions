#include <bits/stdc++.h>

using namespace std;

constexpr int lim=18;
constexpr int limnum=(1<<lim);

struct node{
    int op,l,a,b,r;
};

long long f(int x){
    return 1ll*x*(x+1)/2;
}

void solve(){
    int n,q;
    string s;
    cin>>n>>q;
    vector<node> que(q+10);
    vector<int> dp(limnum),suf0(limnum),pre0(limnum);
    for(int i=0;i<(1<<lim);i++){
        int res=0;
        int dpnum=0;
        bool flag=true;
        bool flagg=true;
        int ress=0;
        for(int j=0;j<lim;j++){
            if(!((i>>j)&1)){//0
                ress++;
            }
            else{
                if(flagg){
                    suf0[i]=ress;
                    flagg=false;
                }
            }
        }
        for(int j=lim-1;j>=0;j--){
            if(!((i>>j)&1)){
                res+=1;
            }
            else{
                if(flag){
                    pre0[i]=res;
                    flag=false;
                }
                dpnum+=f(res);
                res=0;
            }
        }
        if(flag){
            suf0[i]=pre0[i]=lim;
        }
        dpnum+=f(res);
        dp[i]=dpnum;
    }
    cin>>s;
    for(int i=1;i<=q;i++){
        cin>>que[i].op;
        if(que[i].op==1){
            cin>>que[i].l>>que[i].r;
            que[i].l-=1,que[i].r-=1;
        }
        else{
            cin>>que[i].l>>que[i].a>>que[i].b;
            que[i].a-=1,que[i].b-=1;
        }
    }
    int modres=s.size()%lim;
    if(modres)s=s+string(lim-modres,'0');
    n=s.size();
    int res=0;
    vector<int> block;
    for(int i=0;i<n;i++){
        if(i&&i%lim==0){
            block.push_back(res);
            res=0;
        }
        res=(res<<1)|(s[i]-'0');
    };
    block.push_back(res);

    vector<int> b;
    for(int i=1;i<=q;i++){
        if(que[i].op==1){
            b.push_back(que[i].l);
            b.push_back(que[i].r+1);
        }
        else{
            sort(b.begin(),b.end());
            int blockid=0;
            int realid=-1;//end of not reverse
            int cntreverse=0;
            for(auto x:b){
                int nowblockid=x/lim;
                while(blockid<nowblockid){
                    int blockend=lim*(blockid+1)-1;
                    int len=blockend-realid;
                    int reverse_num=(1<<len)-1;
                    if(cntreverse)block[blockid]^=reverse_num;
                    blockid+=1;
                    realid=blockid*lim-1;
                }
                int len1=x-realid-1;
                int len0=lim*(blockid+1)-x;
                int reverse_num=((1<<len1)-1)<<len0;
                if(cntreverse)block[blockid]^=reverse_num;
                realid=x-1;
                cntreverse^=1;
            }

            auto _cut = [&] (int a,int len) -> vector<int> {
                vector<int> blocka;
                int r=a+len-1;
                int idr=r/lim;
                int ida=a/lim;
                while(ida<=idr){
                    int lensuf=lim*(ida+1)-a;
                    int lenpre=lim-lensuf;
                    int resa=block[ida];
                    resa&=((1<<lensuf)-1);
                    a+=lim,ida+=1;
                    resa=(resa<<lenpre)|(block[ida]>>lensuf);
                    blocka.push_back(resa);
                }
                return blocka;
            };
            vector<int> blocka,blockb,blockc;
            blocka=_cut(que[i].a,que[i].l);
            blockb=_cut(que[i].b,que[i].l);
            int cntn=min(blocka.size(),blockb.size());
            for(int i=0;i<cntn;i++){
                blockc.push_back(blocka[i]^blockb[i]);
            }
            int sufnum0=0;
            long long ans=0;
            int id=0;
            int idl=que[i].l/lim;
            while(id<idl){
                if(suf0[blockc[id]]!=lim){
                    ans+=
                    dp[blockc[id]]
                    -f(pre0[blockc[id]])
                    -f(suf0[blockc[id]])
                    +f(sufnum0+pre0[blockc[id]]);
                    sufnum0=suf0[blockc[id]];
                }
                else{
                    sufnum0+=suf0[blockc[id]];
                }
                id+=1;
            }
            for(int j=(id*lim);j<que[i].l;j++){
                int x=(blockc[id]>>(lim-(j-id*lim)-1))&1;
                if(!x){
                    sufnum0+=1;
                }
                else{
                    ans+=f(sufnum0);
                    sufnum0=0;
                }
            }
            if(sufnum0){
                ans+=f(sufnum0);
            }
            cout<<ans<<'\n';
            b.clear();
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}