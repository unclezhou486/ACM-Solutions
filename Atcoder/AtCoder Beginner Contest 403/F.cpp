#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> len(n+10);
	vector<tuple<int,int,int> > a(n+10);//-1 none 0 + 1 *	
	int cnt=0;
	for(int i=1;i<=n;i=(i*10+1)){
		len[i]=++cnt;
		a[i]={0,0,-1};
	}
	for(int i=1;i<=n;i++){
		if(len[i]) continue;
		int res=1e9;
		int resi=-1,resj=-1;
		int type=-1;
		for(int j=1;j<=i-j;j++){
			if(res>len[j]+len[i-j]+1){
				res=len[j]+len[i-j]+1;
				resi=j,resj=i-j;
				type=0;
			}
		}
		for(int j=2;j<=i/j;j++){
			if(i%j==0){
				int res0=0,res1=0;
				if(get<2>(a[j])==0){
					res0=2;
				}
				if(get<2>(a[i/j])==0){
					res1=2;
				}
				if(res>len[j]+len[i/j]+res0+res1+1){
					res=len[j]+len[i/j]+res0+res1+1;
					type=1;
					resi=j;
					resj=i/j;
				}
			}
		}
		len[i]=res;
		a[i]={resi,resj,type};
	}
	auto sol = [&] (auto self,int x) -> string{
		auto [i,j,type]=a[x];
		string res="";
		char ch,chh;
		if(type==-1){
			return to_string(x);
		}
		else if(type==0){
			return self(self,i)+'+'+self(self,j);	
		}
		else{
			res=self(self,i);
			if(get<2>(a[i])==0) res='('+res+')';
			string ress=self(self,j);
			if(get<2>(a[j])==0){
				ress='('+ress+')';
			}
			return res+'*'+ress;
		}
	};
	cout<<sol(sol,n)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
