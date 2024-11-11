#include <bits/stdc++.h>

using namespace std;

string s;

int n;

map<char,int> ma;

int a[200];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    cin>>n;
    for(char i='a';i<='z';i++){
        ma[i]=1;
    }
    for(int i=1;i<=n;i++){
        char ch;
        int cnt;
        cin>>ch>>cnt;
        ma[ch]=cnt;
    }
    int ans=0;
    for(auto v:s){
        int id=v;
        if(a[id]==0){
            if(ma[v]>1){
                ans+=2;
                a[id]=2;
            }
            else{
                ans+=1;
            }
        }
        else{
            ans++;
            a[id]+=1;
        }
        if(a[id]==ma[v]) a[id]=0;
    }
    cout<<ans<<'\n';
}