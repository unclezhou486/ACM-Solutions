#include <bits/stdc++.h>

using namespace std;

int check(string str){
    //int m=str.size();
    if(str[0]<='Z') return 2;
    else{
        for(int i=1;i<str.size();i++){
            if(str[i]=='_') return 3;
        }
        return 1;
    }
}

void change(string &str,int y){
    int x=check(str);
    if(x==y) return ;
    if(x==1){
        if(y==2){
            str[0]-=('a'-'A');
        }
        if(y==3){
            string ress="";
            for(auto v:str){
                if(v<='Z'&&v>='A'){
                    ress+='_';
                    ress+=(v+('a'-'A'));
                }
                else ress+=v;
            }
            str=ress;
        }
    }
    else if(x==2){
        if(y==1){
            str[0]+=('a'-'A');
        }
        else if(y==3){
            change(str,1);
            change(str,3);
        }
    }
    else{
        if(y==1){
            string ress="";
            bool fl=0;
            for(auto v:str){
                if(v=='_') {fl=1;continue;}
                if(fl){
                    v-=('a'-'A');
                    ress+=v;
                    fl=0;
                }
                else{
                    ress+=v;
                }
            }
            str=ress;
        }
        else{
            change(str,1);
            change(str,2);
        }
    }
}

int main(){
    int n;
    string t;
    int tt;
    cin>>n>>t;
    if(t[0]=='C') tt=1;
    else if(t[0]=='P') tt=2;
    else tt=3;
    while(n--){
        string s;
        cin>>s;
        change(s,tt);
        cout<<s<<'\n';
    }
    //if(check(t))   
}