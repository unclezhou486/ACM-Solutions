#include<bits/stdc++.h>

using namespace std;

struct dicTree{
	vector<vector<int> > ne;
	vector<int> cnt,cnt1;
	int tot=0;
	dicTree(){
		ne=vector<vector<int>>(500010,vector<int>(26,0));
		cnt=vector<int>(500010,0);
		cnt1=cnt;
		tot=0;
	}
	void insert(string str){
		int now=0;
		for(auto x:str){
			int res=x-'a';
			if(!ne[now][res]){
				ne[now][res]=++tot;
			}
			now=ne[now][res];
			cnt[now]++;
		}
		cnt1[now]++;
	}
	int query1(string str){// new X -> delete T
		int now=0;
		for(auto x:str){
			int res=x-'a';
			if(!ne[now][res]){
				return 0;
			}
			now=ne[now][res];
		}
		int num=cnt[now];
		now=0;
		for(auto x:str){
			int res=x-'a';
			cnt[ne[now][res]]-=num;
			if(!cnt[ne[now][res]]){
				ne[now][res]=0;
				break;
			}
			now=ne[now][res];
		}
		return num;
	}
	int query2(string str){
		int now=0;
		for(auto x:str){
			int res=x-'a';
			if(!ne[now][res]){
				return 0;
			}
			now=ne[now][res];
			if(cnt1[now]){
				return 1;
			}
		}
		return 0;
	}
};

void solve(){
	int q;
	cin>>q;
	dicTree x,y;
	int ans=0;
	for(int i=1;i<=q;i++){
		int op;
		string s;
		cin>>op>>s;
		if(op==1){
			x.insert(s);
			ans-=y.query1(s);
		}
		else{
			if(!x.query2(s)){
				y.insert(s);
				ans+=1;
			}
		}
		cout<<ans<<'\n';
	}	
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
