#include <bits/stdc++.h>

using namespace std;

vector<int> manachar1(string s){
	int n=s.size();
	vector<int> d1(n);
	for(int i=0,l=0,r=-1;i<n;i++){
		int k=(i>r)?1:min(d1[l+r-i],r-i+1);
		while(0<=i-k&&i+k<n&&s[i-k]==s[i+k]) k++;
		d1[i]=k--;
		if(i+k>r){
			l=i-k;r=i+k;
		}
	}
	return d1;
}

vector<int> z_function(string s){
	int n=(int) s.size();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;++i) {
		if(i<=r&&z[i-l]<r-i+1){
			z[i]=z[i-l];
		}
		else{
			z[i]=max(0,r-i+1);
			while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) ++z[i];
		}
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
	return z;
}

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	vector<int> d1=manachar1(s);
	vector<int> z=z_function(s);
	deque<pair<int,int> > dq;
	vector<int> ans(n);
	bool flag=true;
	for(int i=0;i<n;i++){
		ans[i]=i+1;
		if(i){
			if(s[i]==s[i-1]&&flag){
				ans[i]=1;
			}
			else{
				flag=false;
			}
		}
	}
	for(int i=0;i<n;i++){
		while(dq.size()&&dq.front().first<i){
			dq.pop_front();
		}
		if(dq.size()){
			ans[i]=min(ans[i],dq.front().second+1);
		}
		dq.push_back({d1[i]+i-1,i});
	}
	int id=0;
	// for(int i=0;i<n;i++){
	// 	cout<<i+z[i]<<" \n"[i==n-1];
	// }
	// for(int i=0;i<n;i++){
	// 	cout<<d1[i]<<" \n"[i==n-1];
	// }
	for(int i=0;i<n;i+=2){
		while(i/2==d1[i/2]-1&&i+z[i]>=id+1&&id<n){
			ans[id]=min(ans[id],i/2+1);
			id+=1;
		}
	}
	long long anss=0;
	for(int i=0;i<n;i++){
		// cout<<ans[i]<<" \n"[i==n-1];
		anss^=(1ll*(i+1)*ans[i]);
	}
	cout<<anss<<'\n';
	// for(int i=0;i<n;i++){
	// 	cout<<ans[i]<<" \n"[i==n-1];
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