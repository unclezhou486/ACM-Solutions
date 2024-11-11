#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>k>>m;
        string s;
        cin>>s;
        string res="";
        bool a[k];
        memset(a,0,sizeof a);
        int cnt=0;
        for(char c:s){
            if(res.size()==n) break;
            cnt+=(!a[c-'a']);
            a[c-'a']=1;
            if(cnt==k){
                memset(a,0,sizeof a);
                cnt=0;
                res+=c;
            }
        }
        if(res.size()==n) cout<<"YES\n";
        else{
            cout<<"NO\n";
            for(int i=0;i<k;i++){
                if(!a[i]){
                    while(res.size()<n){
                        res+=(char)('a'+i);
                    }
                }
            }
            cout<<res<<'\n';
        }
    }
}