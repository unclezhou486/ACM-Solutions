#include <bits/stdc++.h>

using namespace std;


void solve(){
	string s;
	cin>>s;
	int n=s.size();
	s='#'+s;
	int L=-1,R=-1;
	for(int i=1;i<=n/2;i++){
		if(s[i]!=s[n-i+1]){
			L=i,R=n-i+1;
			break;
		}
	}
	if(L==-1){
		cout<<0<<'\n';
	}
	else{
		int ans=n;
		int l=1,r=(R-L+1);
		while(l<r){
			int mid=(l+r)>>1;
			bool flag=true;
			int Ll=L,Lr=L+mid-1;
			if(Lr<=n/2){
				vector<int> cnt(30);
				for(int i=Lr+1;i<=n/2;i++){
					if(s[i]!=s[n-i+1]){
						flag=false;
						break;
					}
				}
				for(int i=Ll;i<=Lr;i++){
					cnt[s[i]-'a']+=1;
				}
				for(int i=Ll;i<=Lr;i++){
					if(!cnt[s[n-i+1]-'a']) flag=false;
					cnt[s[n-i+1]-'a']-=1;
				}
			}
			else{
				vector<int> cnt(30);
				for(int i=Ll;i<=Lr;i++){
					cnt[s[i]-'a']+=1;
				}
				for(int i=Lr+1;i<=R;i++){
					if(!cnt[s[i]-'a']){
						flag=false;
						break;
					}
					cnt[s[i]-'a']-=1;
				}
			}
			if(flag) r=mid;
			else l=mid+1;
		}
		ans=min(ans,l);
		l=1,r=(R-L+1);
		while(l<r){
			int mid=(l+r)>>1;
			bool flag=true;
			int Ll=R-mid+1,Lr=R;
			if(Ll>n/2){
				vector<int> cnt(30);
				for(int i=n/2+1;i<Ll;i++){
					if(s[i]!=s[n-i+1]){
						flag=false;
						break;
					}
				}
				for(int i=Ll;i<=Lr;i++){
					cnt[s[i]-'a']+=1;
				}
				for(int i=Ll;i<=Lr;i++){
					if(!cnt[s[n-i+1]-'a']) flag=false;
					cnt[s[n-i+1]-'a']-=1;
				}
			}
			else{
				vector<int> cnt(30);
				for(int i=Ll;i<=Lr;i++){
					cnt[s[i]-'a']+=1;
				}
				for(int i=L;i<Ll;i++){
					if(!cnt[s[i]-'a']){
						flag=false;
						break;
					}
					cnt[s[i]-'a']-=1;
				}
			}
			if(flag) r=mid;
			else l=mid+1;
		}
		ans=min(ans,l);
		cout<<ans<<'\n';
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