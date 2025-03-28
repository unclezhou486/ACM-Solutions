#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node{
	int hp,attack,id;
	bool operator<(const node &a){
		if(hp==a.hp){
			if(attack==a.attack){
				return id<a.id;
			}
			return attack<a.attack;
		}
		return hp<a.hp;
	}
	bool operator>(const node &a){
		if(hp==a.hp){
			if(attack==a.attack){
				return id>a.id;
			}
			return attack>a.attack;
		}
		return hp>a.hp;
	}
};


void solve(){
	int n,u,k,hq;
	cin>>n>>u>>k>>hq;
	vector<node> a(n+10);
	vector<int> cnt(n+10);
	vector<int> vis(n+10);
	multiset<int> att; 
	priority_queue<node,vector<node>,greater<>> q;
	for(int i=1;i<=n;i++){
		cin>>a[i].attack>>a[i].hp;
		a[i].id=i;
		att.insert(a[i].attack);
		q.push((node){a[i].hp,a[i].attack,a[i].id});
	}
	int ans=0;
	while(q.size()&&hq>0){
		auto pos=q.top();
		q.pop();
		auto [hp,attack,id]=pos;
		if(!vis[id]){
			vis[id]=1;
			hp-=u;
		}
		else{
			hp-=u/2;
		}
		cnt[id]+=1;
		if(hp>0&&cnt[id]<k){
			q.push((node){hp,attack,id});
		}
		if(hp<=0) ans+=1,att.extract(attack);
		if(att.size())hq-=*att.rbegin();
	}
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}