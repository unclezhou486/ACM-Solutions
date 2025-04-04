#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	// string s;
	cin>>n;
	vector<vector<int> > fa(n+10,vector<int>(2) );
	string str;
	map<string,int> ma;
	string nowb="main";
	ma[nowb]=1;
	int nown=1;
	int tot=1;

	auto check = [&](int x,int y) -> bool{
		queue<int> q;
		q.push(x);
		while(q.size()){
			int pos=q.front();
			if(pos==y) return true;
			q.pop();
			if(fa[pos][0]) q.push(fa[pos][0]);
			if(fa[pos][1]) q.push(fa[pos][1]);
		}
		return false;
	};
	// char cha=getchar();
	getline(cin,str);
	// while(cha=='\n'||cha=='\r')cha=getchar();
	for(int i=1;i<=n;i++){
		getline(cin,str);
		// sstream
		string res="";
		vector<string> vec;
		for(auto ch:str){
			if(ch==' '){
				if(res!=""){
					vec.push_back(res);
					res="";
				}
			}
			else{
				res=res+ch;
			}
		}
		if(res!="") vec.push_back(res);
		// for(auto x:vec){
		// 	cout<<x<<' ';
		// }
		// cout<<'\n';
		if(!vec.size()) continue;
		if(vec[0]=="commit"){
			++tot;
			fa[tot][0]=nown;
			nown=tot;
			ma[nowb]=tot;
		}
		else if(vec[0]=="branch"&&vec[1]!="-d"){
			if(ma.count(vec[1])) continue;
			if(vec.size()==3){
				int x=0;
				for(auto y:vec[2]){
					x=x*10+(y-'0');
				}
				ma[vec[1]]=x;
			}
			else{
				ma[vec[1]]=nown;
			}
		}
		else if(vec[0]=="branch"&&vec[1]=="-d"){
			if(!ma.count(vec[2])) continue;
			ma.erase(vec[2]);
		}
		else if(vec[0]=="merge"){
			int x=nown,y=ma[vec[1]];
			if(check(y,x)){
				nown=ma[vec[1]];
				ma[nowb]=nown;
			}
			else if(check(x,y)){
				;
			}
			else{
				nown=++tot;
				fa[nown][0]=ma[nowb];
				fa[nown][1]=ma[vec[1]];
				ma[nowb]=nown;
			}
		}
		else if(vec[0]=="checkout"){
			nowb=vec[1];
			nown=ma[nowb];
		}
		else if(vec[0]=="reset"){
			if(vec.size()==2){
				int x=0;
				for(auto ch:vec[1]){
					x=x*10+(ch-'0');
				}
				ma[nowb]=x;
				nown=x;
			}
			else{
				nown=ma[nowb];
			}
		}
	}
	cout<<ma.size()<<'\n';
	for(auto [a,b]:ma){
		cout<<a<<' '<<b<<'\n';
	}
	cout<<tot<<'\n';
	for(int i=1;i<=tot;i++){
		vector<int> vec;
		if(fa[i][0]) vec.push_back(fa[i][0]);
		if(fa[i][1]) vec.push_back(fa[i][1]);
		if(vec.size()) sort(vec.begin(),vec.end());
		cout<<vec.size()<<" ";
		for(auto x:vec){
			cout<<x<<' ';
		}
		cout<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
