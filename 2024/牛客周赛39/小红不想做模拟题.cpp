#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,q;
char a[N];
char b[N];

set<int> s1,s2,s3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='1'&&b[i]=='1'){
            ans++;
        }
        else if(a[i]=='1'){
            s2.insert(i);
        }
        else if(b[i]=='1'){
            s1.insert(i);
        }
        else{
            s3.insert(i);
        }
    }
    cin>>q;
    while(q--){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='A'){
            auto it=s1.lower_bound(l);
            //cout<<*it<<'\n';
            auto itl=it;
            while(it!=s1.end()&&*it<=r){
                it++;
                ans++;
            }
            s1.erase(itl,it);
        }
        else{
            auto it=s2.lower_bound(l);
            auto itl=it;
            while(it!=s2.end()&&*it<=r){
                it++;
                ans++;
            }
            s2.erase(itl,it);         
        }
        auto it=s3.lower_bound(l);
        auto itl=it;
        while(it!=s3.end()&&*it<=r){
            if(c=='A') s2.insert(*it);
            else s1.insert(*it);
            it++;
        }
        s3.erase(itl,it);
        cout<<ans<<'\n';
    }

}