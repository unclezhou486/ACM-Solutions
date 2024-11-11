#include <bits/stdc++.h>

using namespace std;

string str="leetcode";

int a[200010][10];

int ch(char c){
    if(c=='l') return 1;
    else if(c=='e') return 2;
    else if(c=='t') return 3;
    else if(c=='c') return 4;
    else if(c=='o') return 5;
    else if(c=='d') return 6;
}

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int res=7;
    int ans=0;
    int ress=0;
    stack<int> st;
    for(int i=n;i>=1;i--){
        for(int j=0;j<10;j++){
            a[i][j]=a[i+1][j];
        }
        a[i][ch(s[i-1])]=i;
    }
    for(int i=1;i<=n;i++){
        ans=i;
        ans=a[ans][1];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][2];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][2];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][3];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][4];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][5];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][6];
        if(ans==0){cout<<0<<' ';continue;}
        ans=a[ans+1][2];
        if(ans==0){cout<<0<<' ';continue;}
        cout<<ans<<' ';
    }
}