#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int> dd;
	map<int,int> cnt;
	map<pair<int,int>,int> ma;
	auto sol = [&] (int x) -> void {
		int count=0;
		int gd=gcd(x,m);
		for(int i=1;i<=n;i++){
			if(i!=1&&a[i-1]%gd>a[i]%gd){
				count+=1;
			}
		}
		cnt[x]=count;
	};
	for(int i=2;i<=m/i;i++){
		if(m%i==0){
			dd.push_back(i);
			sol(i);
			if(m/i!=i){
				dd.push_back(m/i);
				sol(m/i);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int id,x;
			cin>>id>>x;
			for(auto y:dd){
				int gd=gcd(y,m);
				if(id!=1&&a[id-1]%gd>a[id]%gd){
					cnt[y]-=1;
				}
				if(id!=n&&a[id]%gd>a[id+1]%gd){
					cnt[y]-=1;
				}
				if(id!=1&&a[id-1]%gd>x%gd){
					cnt[y]+=1;
				}
				if(id!=n&&x%gd>a[id+1]%gd){
					cnt[y]+=1;
				}
			}
			a[id]=x;
		}
		else{
			int k;
			cin>>k;
			int gd=gcd(k,m);
			if(gd==1){
				cout<<"YES\n";
			}
			else{
				int cntnum=cnt[gd];
				if(cntnum>=m/gd){
					cout<<"NO\n";
				}
				else{
					cout<<"YES\n";
				}
			}
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