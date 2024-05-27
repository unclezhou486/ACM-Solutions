#include <bits/stdc++.h>

using namespace std;

map<char,int> ma;

bool check(char x){
    if(ma.count(x)) return 1;
    else return 0;
}

char change(bool x){
    if(x) return 'B';
    else return 'A';
}

void solve(){
    ma['A']=1,ma['E']=1,ma['I']=1,ma['O']=1,ma['U']=1,ma['Y']=1;
    int n;
    cin>>n;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int ans=0;
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(check(s[i][0])){
            ans++;
        }   
        else{
            if(i+1==n){
                ans+=2;
                break;
            }
            else if(i==n){
                ans+=1;
                break;
            }
            else if(i+1<=n&&check(s[i+1][0])){
                i++;
                ans+=2;
            }
            else if(i+2<=n&&check(s[i+2][0])){
                i+=2;
                ans+=3;
            }
            else if(i+1<=n&&s[i+1].size()>=2&&check(s[i+1][1])){
                i+=1;
                ans+=3;
            }
            else if(s[i].size()>=2&&check(s[i][1])){
                ans+=2;
            }
            else if(s[i].size()>=3&&check(s[i][2])){
                ans+=3;
            }
            else{
                flag=0;
                break;
            }
        }
    }
    if(!flag) cout<<"*\n";
    else cout<<ans<<'\n';
    return;
    //string str;
    //string s;
    //vector<int> vis(2*(n+1));
    //int cnt=0;
    //for(int i=1;i<=n;i++){
    //    cin>>str;
    //    if(str.size()==1){
    //        s+=change(check(str[0]));
    //        cnt++;
    //        vis[cnt]=check(str[0]);
    //    }
    //    else{
    //        if(check(str[0])){
    //            s+=change(check(str[0]));
    //            cnt++;
    //            vis[cnt]=check(str[0]);
    //        }
    //        else{
    //            s+=change(check(str[0])),cnt++;
    //            if(check(str[1]))s+=change(check(str[1])),cnt++;
    //        }
    //    }
    //}
    //s='#'+s;
    //cout<<s<<'\n';
    //bool flag=1;
    //for(int i=1;i<=cnt;i++){
    //    if(i+2<=cnt&&s[i]=='A'&&s[i+1]=='A'&&s[i+2]=='A'){
    //        flag=0;
    //    }
    //}
    //if(!flag){
    //    cout<<"*\n";
    //    return;
    //}
    //else{
    //    int ans=cnt;
    //    for(int i=1;i<cnt;i++){
    //        if(s[i]=='B'){
    //            if(vis[i]) continue;
    //            if(s[i-1]=='B'&&s[i]=='B') {ans--;continue;}
    //            if((((i-2==0)||s[i-2]=='B')&&(i-1>=1&&s[i-1]=='A')&&(i+1<=cnt&&s[i+1]=='A')&&(i+1==cnt||s[i+2]=='B'))){
    //                ans--;
    //                vis[i+2]=1;
    //                continue;
    //            }
    //        }
    //    }
    //    if(s[cnt]=='B') ans--;
    //    cout<<ans<<'\n';
    //    return;
    //}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}