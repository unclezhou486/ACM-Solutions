#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	long long k;
	cin>>n>>k;
	string s;
	vector<long long> a(n),pre(n),suf(n);
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(s[i]=='0'){
			a[i]=-1e13;
		}
		pre[i]=max(a[i],0ll);
		if(i) pre[i]=max(pre[i-1]+a[i],0ll);
	}
	for(int i=n-1;i>=0;i--){
		suf[i]=max(0ll,a[i]);
		if(i!=n-1) suf[i]=max(suf[i+1]+a[i],0ll);
	}
	long long maxsum=a[0];
	for(int i=0;i<n;i++){
		long long res=a[i];
		if(i) res+=pre[i-1];
		if(i!=n-1) res+=suf[i+1];
		maxsum=max(maxsum,res);
	}
	auto print = [&](vector<long long> &a) -> void{
		int nn=a.size();
		for(int i=0;i<nn;i++){
			cout<<a[i]<<" \n"[i==nn-1];
		}
	};
	if(maxsum==k){
		cout<<"Yes\n";
		print(a);
	}
	else if(maxsum>k){
		cout<<"No\n";
	}
	else{
		int id=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				id=i;
				break;
			}
		}
		if(id==-1){
			cout<<"No\n";
		}
		else{
			long long res=0;
			if(id) res+=pre[id-1];
			if(id!=n-1) res+=suf[id+1];
			a[id]=k-res;
			cout<<"Yes\n";
			print(a);
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
