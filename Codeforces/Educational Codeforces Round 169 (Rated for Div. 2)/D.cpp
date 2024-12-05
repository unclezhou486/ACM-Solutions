#include <bits/stdc++.h>

using namespace std;

int change(char ch){
	if(ch=='B') return 1;
	else if(ch=='G') return 2;
	else if(ch=='R') return 4;
	else return 8;
}

string add(char a,char b){
	if(change(a) >change(b)){
		swap(a,b);
	}
	string res="";
	res=res+a;
	res=res+b;
	return res;
}

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n+10);
	vector<vector<char> > c(n+10,vector<char>(2));
	// set<int> se;
	map<string,set<int> > ma; 
	for(int i=1;i<=n;i++){
		cin>>c[i][0]>>c[i][1];
		string res=add(c[i][0],c[i][1]);
		a[i]=change(c[i][0])+change(c[i][1]);
		ma[res].insert(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		if(a[x]&a[y]){
			cout<<y-x<<'\n';
		}
		else{
			int ans=1e9;
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					string res=add(c[x][i],c[y][j]);
					// if(ma[res].lower_bound(x))
					auto &se=ma[res];
					auto it=se.upper_bound(x);
					if(it!=se.end()&&(*it)<y) ans=min(ans,y-x);
					if(it!=se.begin()){
						it--;
						ans=min(ans,x-(*it)+y-(*it));
					}
					it=se.upper_bound(y);
					if(it!=se.end()){
						ans=min(ans,(*it)-x+(*it)-y);
					}
					// it=ma[res].upper_bound(y);
				}
			}
			if(ans==1e9) ans=-1;
			cout<<ans<<'\n';
		}
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