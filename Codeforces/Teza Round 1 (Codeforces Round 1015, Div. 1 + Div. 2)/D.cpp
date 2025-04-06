#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> ans(n+10,-1);
	int id=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ans[i]==-1){
			cnt=0;
			for(int j=i;j<=n;j+=k){
				ans[j]=id;
				cnt++;
				if(cnt==m+1){
					cnt=0;
					id+=1;
				}
			}
		}
		cout<<ans[i]<<" \n"[i==n];
	}

	// vector<int> ans(n+10,-1);
	// ans[1]=0;
	// int res=n-1-(m*k);
	// if(res<k){
	// 	for(int i=k+1;i<=n;i+=k){
	// 		ans[i]=0;
	// 	}
	// 	for(int i=n;(i-res+1)>=1;i-=k){
	// 		for(int j=i,id=1;j>=i-res+1;j--,id++){
	// 			ans[j]=id;
	// 		}
	// 	}
	// 	for(int i=1;i<=n;i++){
	// 		if(ans[i]!=-1)cout<<ans[i]<<" \n"[i==n];
	// 		else cout<<0<<" \n"[i==n];
	// 	}
	// }
	// else{
	// 	int res=n-m*k;
	// 	int x=res/(m+1);
	// 	vector<int> vec(m+1,x);
	// 	int ress=res-x*(m+1);
	// 	// cout<<ress<<' '<<res<<' '<<x<<'\n';
	// 	for(int i=0;ress;i++,ress--){
	// 		vec[i]+=1;
	// 	}
	// 	for(int i=0;i<m;i++){
	// 		int id=0;
	// 		for(int j=0;j<vec[i];j++,id++){
	// 			cout<<id<<' ';
	// 		}
	// 		for(int j=k-1;j>=0;j--,id++){
	// 			cout<<id<<' ';
	// 		}
	// 	}
	// 	for(int j=0;j<vec[m];j++){
	// 		cout<<j<<' ';
	// 	}
	// 	cout<<'\n';
	// }
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


/*

#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int res=n-m*k;
	int x=res/(m+1);
	vector<int> vec(m+1,x);
	int ress=res-x*(m+1);
	// cout<<ress<<' '<<res<<' '<<x<<'\n';
	for(int i=0;ress;i++,ress--){
		vec[i]+=1;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<vec[i];j++){
			cout<<j<<' ';
		}
		for(int j=k-1;j>=0;j--){
			cout<<j<<' ';
		}
	}
	for(int j=0;j<vec[m];j++){
		cout<<j<<' ';
	}
	cout<<'\n';
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

*/