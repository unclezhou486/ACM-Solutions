#include <bits/stdc++.h>

using namespace std;

string s;
vector<string> vec;

bool cmp(string a,string b){
    if(a.size()==b.size()){
        return a<b;
    }
    else{
        return a.size()<b.size();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        int x=s[i]-'0';
        string res="";
        res+=s[i];
        while(x%2&&i+1<n){
            i++;
            x=s[i]-'0';
            res+=s[i];
        }
        vec.push_back(res);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(auto x:vec){
        cout<<x<<'\n';
    }
}