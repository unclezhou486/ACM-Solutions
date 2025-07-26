#include <bits/stdc++.h>

using namespace std;

struct Bit{
	int n;
	vector<long long> bit1,bit2,cnt;
	void init(int n){
		this->n=n;
		bit1.assign(n+10,{});
		bit2.assign(n+10,{});
		cnt.assign(n+10,{});
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int k,long long x,long long y){
		for(;k<=n;k+=lowbit(k)){
			bit1[k]+=x;
			bit2[k]+=y;
			cnt[k]+=1;
		}
	}
	long long query1(int x){
		long long res=0;
		for(;x;x-=lowbit(x)) res+=bit1[x];
		return res;
	}
	long long sum1(int l,int r){
		return query1(r)-query1(l-1);
	}
	long long query2(int x){
		long long res=0;
		for(;x;x-=lowbit(x)) res+=bit2[x];
		return res;
	}
	long long sum2(int l,int r){
		return query2(r)-query2(l-1);
	}
	long long query3(int x){
		long long res=0;
		for(;x;x-=lowbit(x)) res+=cnt[x];
		return res;
	}
	long long count(int l,int r){
		return query3(r)-query3(l-1);
	}
}bit;

void solve(){
	int n;
	cin>>n;
	bit.init(2*n+10);
	int res=n+2;
	int cnt0=0,cnt1=0;
	int lmin=1;
	int rmax=2*n+8;
	long long ans=0;
	bit.add(res,0,0);
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='0'){
			cnt0++;
		}
		else{
			cnt1++;
		}
		int rescnt=cnt1-cnt0;
		int ress=rescnt+res;
		ans+=cnt1*bit.count(lmin,ress)-bit.sum1(lmin,ress)+(cnt0*bit.count(ress+1,rmax)-bit.sum2(ress+1,rmax));
		bit.add(ress,cnt1,cnt0);
	}
	cout<<ans<<'\n';
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