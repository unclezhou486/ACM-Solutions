#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > change(vector<char> &s,vector<char> &t){
	vector<pair<int,int> > res;
	int n=s.size();
	int cnt0=0,cnt1=0;
	for(int i=0;i<n;i++){
		if(t[i]=='0'){
			res.push_back({cnt0,cnt1});
			cnt0=cnt1=0;
		}
		if(s[i]=='1') cnt1++;
		else cnt0++;
		if(t[i]=='0'){
			res.push_back({cnt0,cnt1});
			cnt0=cnt1=0;
		}
	}
	if(cnt0||cnt1){
		res.push_back({cnt0,cnt1});
	}
	return res;
}

void solve(){
	int n;
	cin>>n;
	vector<char> s1(n),s2(n);
	vector<char> t1(n),t2(n);
	for(int i=0;i<n;i++){
		cin>>s1[i];
	}
	for(int i=0;i<n;i++){
		cin>>s2[i];
	}
	for(int i=0;i<n;i++){
		cin>>t1[i];
	}
	for(int i=0;i<n;i++){
		cin>>t2[i];
	}
	vector<pair<int,int> > vec1,vec2;
	vec1=change(s1,t1);
	vec2=change(s2,t2);
	int id1=0,id2=0;
	int ans=0;
	while(id1<vec1.size()&&id2<vec2.size()){
		auto &[cnt10,cnt11]=vec1[id1];
		auto &[cnt20,cnt21]=vec2[id2];
		int res1=cnt10+cnt11;
		int res2=cnt20+cnt21;
		if(res1>res2){
			int ress0=min(cnt10,cnt20);
			int ress1=min(cnt11,cnt21);
			cnt10-=ress0;
			cnt20-=ress0;
			cnt11-=ress1;
			cnt21-=ress1;
			ans+=ress0+ress1;
			if(cnt20){
				cnt11-=cnt20;
				cnt20=0;
			}
			else{
				cnt10-=cnt21;
				cnt21=0;
			}
		}
		else{
			int ress0=min(cnt10,cnt20);
			int ress1=min(cnt11,cnt21);
			ans+=ress0+ress1;
			cnt10-=ress0;
			cnt20-=ress0;
			cnt11-=ress1;
			cnt21-=ress1;
			if(cnt10){
				cnt21-=cnt10;
				cnt10=0;
			}
			else{
				cnt20-=cnt11;
				cnt11=0;
			}
		}
		if(cnt10+cnt11==0) id1++;
		if(cnt20+cnt21==0) id2++;
	}
	cout<<ans<<'\n';
}

int main(){
	// freopen("edit2.in","r",stdin);
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

011 1 0 1
1 1 10 1 0

*/