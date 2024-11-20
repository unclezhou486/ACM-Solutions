#include <bits/stdc++.h>

using namespace std;

struct node{
	int l,r,c;
	bool operator<(const node a) const {
		return l<a.l;
	}
};
	// set<node> se;
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> num(n+10);
	set<node> se;
	for(int i=1;i<=n;i++){
		num[i]=1;
		se.insert((node){i,i,i});
	}
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int x,c;
			cin>>x>>c;
			auto it=se.upper_bound((node){x,x,x});
			it--;
			auto [ll,rr,cc]=*it;
			for(;it!=se.end()&&(*it).c==cc;it++) rr=(*it).r;
			auto itr=it;
			it=se.upper_bound((node){x,x,x});
			it--;
			for(;(*it).c==cc;it--){
				if(it==se.begin()) break;
			}
			if((*it).c!=cc) it++;
			ll=(*it).l;
			auto itl=it;
			for(auto it=itl;it!=itr;it++){
				auto [l,r,c]=*it;
				num[c]-=(r-l+1);
			}
			se.erase(itl,itr);
			se.insert((node){ll,rr,c});
			num[c]+=(rr-ll+1);
			// num[c]+=
		}
		else{
			int c;
			cin>>c;
			cout<<num[c]<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}