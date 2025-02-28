#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	s='#'+s;
	vector<long long> sufo(n+10),pren(n+10),prey(n+10),sufs(n+10),preye(n+10),sufes(n+10); 
	long long cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		pren[i]=pren[i-1];
		prey[i]=prey[i-1];
		preye[i]=preye[i-1];
		if(s[i]=='N'){
			pren[i]+=1;
		}
		else if(s[i]=='Y'){
			prey[i]+=1;
		}
		else if(s[i]=='E'){
			preye[i]+=prey[i-1];
		}
		if(s[i]=='O'){
			cnt0+=pren[i];
		}
		if(s[i]=='S'){
			cnt1+=preye[i];
		}
	}
	for(int i=n;i>=1;i--){
		sufo[i]=sufo[i+1];
		sufs[i]=sufs[i+1];
		sufes[i]=sufes[i+1];
		if(s[i]=='O'){
			sufo[i]+=1;
		}
		else if(s[i]=='S'){
			sufs[i]+=1;
		}
		else if(s[i]=='E'){
			sufes[i]+=sufs[i+1];
		}
	}
	cout<<cnt1<<' '<<cnt0<<'\n';
	if(cnt1==cnt0){
		cout<<"DUI DUI DUIMA\n";
		return;
	}
	bool flag=cnt1>cnt0;
	for(int i=1;i<=n;i++){
		long long res1=0,res0=0;
		if(s[i]=='Y'){
			res1-=sufes[i];
		}
		else if(s[i]=='E'){
			res1-=prey[i]*sufs[i];
		}
		else if(s[i]=='S'){
			res1-=preye[i];
		}
		else if(s[i]=='N'){
			res0-=sufo[i];
		}
		else if(s[i]=='O'){
			res0-=pren[i];
		}
		long long cntt1=0,cntt0=0;
		cntt1=cnt1+res1,cntt0=cnt0+res0;
		long long cnttt1,cnttt0;
		bool flagg;
		cnttt1=cntt1,cnttt0=cntt0+sufo[i+1];
		flagg=cnttt1>cnttt0;
		if(cnttt1!=cnttt0&&flagg!=flag){
			if(flag){
				cout<<"O BUDUI BUDUI\n";
			}
			else{
				cout<<"O DUI DE\n";
			}
			return;
		}

		cnttt1=cntt1,cnttt0=cntt0+pren[i-1];
		flagg=cnttt1>cnttt0;
		if(cnttt1!=cnttt0&&flagg!=flag){
			if(flag){
				cout<<"O BUDUI BUDUI\n";
			}
			else{
				cout<<"O DUI DE\n";
			}
			return;
		}

		cnttt1=cntt1+sufes[i+1],cnttt0=cntt0;
		flagg=(cntt1+sufes[i+1])>cntt0;
		if(cnttt1!=cnttt0&&flagg!=flag){
			if(flag){
				cout<<"O BUDUI BUDUI\n";
			}
			else{
				cout<<"O DUI DE\n";
			}
			return;
		}

		cnttt1=cntt1+preye[i-1];
		cnttt0=cntt0;
		flagg=(cntt1+preye[i-1])>(cntt0);
		if(cnttt1!=cnttt0&&flagg!=flag){
			if(flag){
				cout<<"O BUDUI BUDUI\n";
			}
			else{
				cout<<"O DUI DE\n";
			}
			return;
		}

		cnttt1=cntt1+prey[i-1]*sufs[i+1];
		cnttt0=cntt0;
		flagg=(cntt1+prey[i-1]*sufs[i+1])>(cntt0);
		if(cnttt1!=cnttt0&&flagg!=flag){
			if(flag){
				cout<<"O BUDUI BUDUI\n";
			}
			else{
				cout<<"O DUI DE\n";
			}
			return;
		}
	}
	if(flag){
		cout<<"DUI DE\n";
	}
	else {
		cout<<"BUDUI BUDUI\n";
	}
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}