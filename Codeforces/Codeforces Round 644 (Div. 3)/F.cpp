#include <bits/stdc++.h>

using namespace std;

int dif(string a,string b){
	int res=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) res++;
	}
	return res;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<string> s(n);
	int res=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(i) res=max(res,dif(s[i],s[i-1]));
	}
	if(n==1||!res){
		cout<<s[0]<<'\n';
		return;
	}
	else{
		for(int i=0;i<n;i++){
			for(int k=i+1;k<n;k++){
				vector<int> id;
				for(int j=0;j<m;j++){
					if(s[i][j]!=s[k][j]){
						id.push_back(j);
					}
				}
				if(id.size()<=2){
					string ans=s[i];
					if(id.size()==1){
						int id0=id[0];
						for(int q='a';q<='z';q++){
							ans[id0]=q;
							bool flag=true;
							for(int w=0;w<n;w++){
								if(dif(ans,s[w])>1){
									flag=false;
									break;
								}
							}
							if(flag){
								cout<<ans<<'\n';
								return;
							}
						}
					}
					else if(id.size()==2){
						int id0=id[0],id1=id[1];
						for(int q='a';q<='z';q++){
							ans[id0]=q;
							for(int e='a';e<='z';e++){
								ans[id1]=e;
								bool flag=true;
								for(int w=0;w<n;w++){
									if(dif(ans,s[w])>1){
										flag=false;
										break;
									}
								}
								if(flag){
									cout<<ans<<'\n';
									return;
								}
							}
						}
					}
				}
			}
		}
		cout<<-1<<'\n';
		return;
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