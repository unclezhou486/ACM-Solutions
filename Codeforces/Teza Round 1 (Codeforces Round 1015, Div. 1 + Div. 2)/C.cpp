#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+10),b(n+10);
	vector<int> ida(n+10),idb(n+10);
	vector<pair<int,int> > ans; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		// ida[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		// idb[b[i]]=i;
	}
	int idda=-1,iddb=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
			idda=i;
			iddb=i;
		}
	}
	if(idda!=-1&&idda!=n/2+1){
		swap(a[n/2+1],a[idda]);
		swap(b[n/2+1],b[iddb]);
		ans.push_back({n/2+1,idda});
	}
	for(int i=1;i<=n;i++){
		ida[a[i]]=i;
		idb[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=b[n-i+1]){
			int x=i,y=ida[b[n-i+1]];
			swap(ida[a[x]],ida[a[y]]);
			swap(idb[b[x]],idb[b[y]]);
			swap(a[x],a[y]);
			swap(b[x],b[y]);
			ans.push_back({x,y});
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[n-i+1]){
			flag=false;
			break;
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i]<<" \n"[i==n];
	// }
	// for(int i=1;i<=n;i++){
	// 	cout<<b[i]<<" \n"[i==n];
	// }
	// for(int i=1;i<=n;i++){
	// 	cout<<ida[i]<<" \n"[i==n];
	// }
	// for(int i=1;i<=n;i++){
	// 	cout<<idb[i]<<" \n"[i==n];
	// }
	if(flag){
		cout<<ans.size()<<'\n';
		for(auto [a,b]:ans){
			cout<<a<<' '<<b<<'\n';
		}
	}
	else{
		cout<<-1<<'\n';
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
