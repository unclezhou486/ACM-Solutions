#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

struct pam{
    int sz,tot,last;
    int cnt[N],ch[N][26],len[N],fail[N];
    char s[N];
    int node(int l) {
        sz++;
        memset(ch[sz],0,sizeof (ch[sz]));
        len[sz]=l;
        fail[sz]=cnt[sz]=0;
        return sz;
    }
    void clear(){
        sz=-1;
        last=0;
        s[tot=0]='$';
        node(0);
        node(-1);
        fail[0] = 1;
    }
    int getfail(int x){
        while(s[tot-len[x]-1]!=s[tot]) x=fail[x];
        return x;
    }
    void insert(char c){
        s[++tot]=c;
        int now=getfail(last);
        if(!ch[now][c-'a']){
            int x=node(len[now]+2);
            fail[x]=ch[getfail(fail[now])][c-'a'];
            ch[now][c-'a']=x;
        }
        last=ch[now][c-'a'];
        cnt[last]++;
    }
}a,b;

void solve(){
    int n;
    cin>>n;
    vector<char> s(n);
    vector<int> pre(n),suf(n);
    for(int i=0;i<n;i++) cin>>s[i];
    //cout<<a.sz<<' '<<b.sz<<'\n';
    a.clear();
    b.clear();
    for(int i=0;i<n;i++){
        a.insert(s[i]);
        b.insert(s[n-i-1]);
        pre[i]=a.sz;
        suf[n-i-1]=b.sz;
    } 
    int m;
    cin>>m;
    while(m--){
        int ll,rr;
        cin>>ll>>rr;
        ll--,rr--;
        ll--,rr++;
        int ans1=0,ans2=0;
        if(ll>=0) ans1=pre[ll]-1;
        if(rr<n) ans2=suf[rr]-1;
        cout<<ans1<<' '<<ans2<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
