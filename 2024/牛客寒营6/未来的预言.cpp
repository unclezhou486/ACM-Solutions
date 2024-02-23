#include <bits/stdc++.h>

using namespace std;

char op;
int x;
int b,c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>op>>op>>x;
    string s;
    cin>>s;
    int i=0;
    for(i=0;i<s.size();i++){
        char a=s[i];
        if(a=='R'){
            b++;
        }
        else c++;
        if(b>x/2){
            cout<<"kou!\n";
            cout<<i+1<<'\n';
            return 0;
        }
        if(c>x/2){
            cout<<"yukari!\n";
            cout<<i+1<<'\n';
            return 0;
        }
    }
    cout<<"to be continued.\n";
    cout<<s.size()<<'\n';
}