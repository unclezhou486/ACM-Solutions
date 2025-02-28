#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int aval=0;
	cin>>aval;
	vector<int> a(n+10),b(m+10);
	for(int i=2;i<=n;i++){
		// int x;
		cin>>a[i];
		// a.insert(x);
	}
	int minid=-1;
	int minval=1e9;
	for(int i=1;i<=m;i++){
		// int x;
		cin>>b[i];
		// cin>>x;
		// b.insert(x);
	}
	sort(a.begin()+2,a.begin()+1+n);
	sort(b.begin()+1,b.begin()+1+m);
	for(int i=1;i<=m;i++){
		if(b[i]>aval){
			if(b[i]<minval){
				minval=b[i];
				minid=i;
			}
		}
	}
	for(int i=1;i<=m;i++){
		long long ans=0;
		int L=-1;
		for(int l=1;l+i-1<=m;l+=i){
			int r=l+i-1;
			if(b[r]<=aval){
				ans+=1;
			}
			else{
				L=l;
				break;
			}
		}
		if(L!=-1){
			int resx=minid-L;
			int resy=i-(resx);
			int resr=m-(resy)+1;
			auto it=lower_bound(a.begin()+2,a.begin()+1+n,b[resr])-a.begin();
			ans+=(n-it+1)+1;
			resr-=i;
			for(;resr>=minid;resr-=i){
				auto it=lower_bound(a.begin()+2,a.begin()+1+n,b[resr])-a.begin();
				ans+=(n-it+1)+1;
			}
		}
		cout<<ans<<" \n"[i==m];
	}
	// for(int i=1;i<=m;i++){
	// 	int ans=0;
	// 	for(int r=i;r<=n;r+=i){
	// 		int l=r-i+1;
	// 		if(b[l]>aval){
	// 			auto it=lower_bound(a.begin()+2,a.begin()+1+n,b[l])-a.begin();
	// 			ans+=(n-it+1)+1;
	// 		}
	// 		else if(b[r]>aval){
	// 			auto it=lower_bound(a.begin()+2,a.begin()+1+n,minval)-a.begin();
	// 			ans+=(n-it+1)+1;
	// 		}
	// 		else{
	// 			ans+=1;
	// 		}
	// 	}
	// 	cout<<ans<<" \n"[i==m];
	// }
	// for(int i=1;i<=m;i++){
	// 	int j=m-i+1;
	// 	int ans=0;
	// 	for(;j>=1;j-=i){
	// 		int l=j,r=l+i-1;
	// 		if(b[l]>aval){
	// 			auto it=lower_bound(a.begin()+2,a.begin()+1+n,b[l])-a.begin();
	// 			ans+=(n-it+1)+1;
	// 		}
	// 		else if(b[r]>aval){
	// 			auto it=lower_bound(a.begin()+2,a.begin()+1+n,minval)-a.begin();
	// 			ans+=(n-it+1)+1;
	// 		}
	// 		else{
	// 			ans+=1;
	// 		}
	// 		// if(b[j]<=aval){
	// 		// 	ans+=1;
	// 		// }
	// 		// else{
	// 		// 	auto it=lower_bound(a.begin()+2,a.begin()+1+n,b[j])-a.begin();
	// 		// 	ans+=(n-it+1)+1;
	// 		// }
	// 	}
	// 	// if(b[1]<=aval){
	// 	// 	ans+=1;
	// 	// }
	// 	// else{
	// 	// 	auto it=lower_bound(a.begin()+2,a.begin()+1+n,b[1])-a.begin();
	// 	// 	ans+=(n-it+1)+1;
	// 	// }
	// 	cout<<ans<<" \n"[i==m];
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