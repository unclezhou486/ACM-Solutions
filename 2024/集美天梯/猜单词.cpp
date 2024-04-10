#include <bits/stdc++.h>

using namespace std;

struct node{
    string str;
    int a,b;
}c[5];

char str[10];
queue<string> q;
int ans=0;

void dfs(int x,char ch){
    str[x]=ch;
    if(x==2){
        set<char> se;
        se.insert(str[0]);
        se.insert(str[1]);
        se.insert(str[2]);
        for(int i=0;i<5;i++){
            int aa=0,bb=0;
            for(int j=0;j<3;j++){
                if(str[j]==c[i].str[j]){
                    bb++;
                }
                if(se.find(c[i].str[j])!=se.end()) aa++;
            }
            if(aa!=c[i].a||bb!=c[i].b){
                return;
            }
        }
        string ss=str;
        q.push(ss);
        ans++;
        return;
    }
    for(char i='A';i<='Z';i++){
        dfs(x+1,i);
    }
}

int main(){
    for(int i=0;i<5;i++){
        cin>>c[i].str>>c[i].a>>c[i].b;
    }
    for(int i='A';i<='Z';i++){
        dfs(0,i);
    }
    cout<<ans<<'\n';
    while(q.size()) cout<<q.front()<<'\n',q.pop();
}