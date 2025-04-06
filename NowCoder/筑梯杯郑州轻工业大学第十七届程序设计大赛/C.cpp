#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+10),b(n+10);
	vector<int> ans(n+10);
	map<int,int> ma;
	vector<int> val(n+10);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin()+1,b.begin()+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]!=b[i-1]){
			cnt++;
		}
		ma[b[i]]=cnt;
		val[cnt]=b[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=ma[a[i]];
	}
	int id=1;
	int res=0;
	vector<int> vec;
	for(int i=0;i<n;i++){
		vec.push_back(i);
	}
	k=(n*(n+1))/2-k+1;
	while(k){
		int rescnt=0;
		res+=1;
		vector<int> vecc;
		if(res==0){
			rescnt=vec.size();
		}
		else{
			for(auto x:vec){
				if((x+1<=n&&b[x+1]==res)){
					rescnt+=(n-x);
					vecc.push_back(x+1);
				}
			}
		}
		if(rescnt>=k&&res){
			ans[id]=res;
			vec=vecc;
			id+=1;
			res=-1;
		}
		else if(rescnt>=k&&!res){
			k=0;
		}
		else{
			k-=rescnt;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i])cout<<val[ans[i]]<<" ";
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