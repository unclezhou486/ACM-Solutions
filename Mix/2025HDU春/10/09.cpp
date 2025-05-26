#pragma GCC O(2)
#pragma GCC O(3)

#include <bits/stdc++.h>

using namespace std;

vector<int> su;
vector<vector<int> > yinzi(1000010);
long long val[1000010];
long long vala[1000010];

void table(){
	vector<int> vis(1000010);
	vis[1]=1;
	for(int i=2;i<=1000000;i++){
		if(vis[i]) continue;
		su.push_back(i);
		yinzi[i].push_back(i);
		for(int j=i*2;j<=1000000;j+=i){
			vis[j]=1;
			yinzi[j].push_back(i);
		}
	}
	for(int i=2;i<=1000000;i++){
		int res=i;
		for(auto x:yinzi[i]){
			int cnt=0;
			while(res%x==0){
				res/=x;
				cnt++;
			}
			if(cnt%2){
				vala[i]^=val[x];
			}
		}
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int anslen,l,r;
	anslen=0,l=-1,r=-1;
	long long res=0;
	// map<int,int> la;
	vector<long long> pre(n+10);
	vector<int> la(n+10,-1);
	vector<pair<long long,int> > vec;
	vec.push_back({0,0});
	for(int i=1;i<=n;i++){
		res^=vala[a[i]];
		pre[i]=res;
		vec.push_back({res,i});
	}
	sort(vec.begin(),vec.end());
	int idx=0;
	vector<int> real(n+10);
	for(int i=0;i<vec.size();i++){
		if(i&&vec[i].first!=vec[i-1].first){
			idx++;
		}
		real[vec[i].second]=idx;
	}
	for(int i=0;i<=n;i++){
		int id=real[i];
		if(la[id]!=-1){
			if(i-la[id]>anslen){
				anslen=i-la[id];
				l=la[id]+1;
				r=i;
			}
		}
		else{
			la[id]=i;
		}
	}
	cout<<l<<' '<<r<<'\n';
}

int main(){
	mt19937_64 myrand(time(0));
	for(int i=1;i<=1000000;i++){
		val[i]=myrand();
	}
	table();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}