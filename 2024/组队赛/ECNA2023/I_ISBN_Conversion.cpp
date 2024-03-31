#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin>>str;
    int n=str.size();
    //int res=0;
    int cnt=0;
    int d=0;
    vector<int> vec;
    for(auto v:str){
        if(v=='-'){
            cnt++;
        }
        else if(v=='X'){
            vec.push_back(10);
            if(vec.size()!=10){
                cout<<"invalid\n";
                return;
            }
        }
        else{
            d=v-'0';
            vec.push_back(d);
        }
    }
    //cout<<"CCF";
    if(str[0]=='-'||str[n-1]=='-'){
        cout<<"invalid\n";
        return;
    }
    //cout<<"CCF\n";
    for(int i=1;i<n;i++){
        if(str[i]=='-'){
            if(str[i-1]=='-'){
                cout<<"invalid\n";
                return;
            }
        }
    }
    //cout<<"CCF\n";
    if(cnt==3&&str[n-2]!='-'){
        cout<<"invalid\n";
        return;
    }
    else{
        //cout<<"CCF\n";
        if(vec.size()!=10){
            cout<<"invalid\n";
            return;
        }
        int res=0;
        for(int i=0;i<10;i++){
            res+=vec[i]*(10-i);
        }
        //cout<<res<<'\n';
        if(res%11){
            cout<<"invalid\n";
            return;
        }
        else{
            cout<<"978-";
            res=0;
            res+=9+3*7+8;
            for(int i=0;i<9;i++){
                int dd=3;
                if(i%2) dd=1;
                res+=vec[i]*(dd);
            }
            for(int i=0;i<=9;i++){
                if(((i+res)%10)==0)vec[9]=i;
            }
            int count=0;
            for(auto v:str){
                if(v=='-'){
                    cout<<v;
                }
                else{
                    if(vec[count]==10) cout<<"X";
                    else cout<<vec[count];
                    count++;
                }
            }
            cout<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}