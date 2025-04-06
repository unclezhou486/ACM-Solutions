#include <bits/stdc++.h>

using namespace std;

int day[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check (int x){
	if(x==2000){
		return 1;
	}
	else return x%4==0;
}

void solve(){
	// string a,b;
	// cin>>a>>b;
	int ya,ma,da,ha,mia,sa;
	int yb,mb,db,hb,mib,sb;
	scanf("%d-%d-%dT%d:%d:%d",&ya,&ma,&da,&ha,&mia,&sa);
	scanf("%d-%d-%dT%d:%d:%d",&yb,&mb,&db,&hb,&mib,&sb);
	if(ya==yb&&ma==mb&&da==db){
		int ans=((hb*3600+mib*60+sb)-(ha*3600+mia*60+sa));
		if(ans>=8*3600){
			cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
	else{
		if(ya==yb-1){
			if(ma==12&&da==31&&mb==1&&db==1){
				int ans=((hb*3600+mib*60+sb)+(24*3600-(ha*3600+mia*60+sa)));
				if(ans>=8*3600){
					cout<<"Yes\n";
				}
				else{
					cout<<"No\n";
				}
			}
			else{
				cout<<"Yes\n";
			}
		}
		else if(ya==yb){
			if(ma==mb-1){
				if(ma==2){
					if(((check(ya)&&da==29)||(!check(ya)&&da==28))&&db==1){
						int ans=((hb*3600+mib*60+sb)+(24*3600-(ha*3600+mia*60+sa)));
						if(ans>=8*3600){
							cout<<"Yes\n";
						}
						else{
							cout<<"No\n";
						}
					}
					else{
						cout<<"Yes\n";
					}
				}
				else{
					if(da==day[ma]&&db==1){
						int ans=((hb*3600+mib*60+sb)+(24*3600-(ha*3600+mia*60+sa)));
						if(ans>=8*3600){
							cout<<"Yes\n";
						}
						else{
							cout<<"No\n";
						}
					}
					else{
						cout<<"Yes\n";
					}
				}
			}
			else if(ma<mb){
				cout<<"Yes\n";
			}
			else if(ma==ma){
				if(da==db-1){
					int ans=((hb*3600+mib*60+sb)+(24*3600-(ha*3600+mia*60+sa)));
					if(ans>=8*3600){
						cout<<"Yes\n";
					}
					else{
						cout<<"No\n";
					}
				}
				else{
					cout<<"Yes\n";
				}
			}
		}
		else if(ya<yb){
			cout<<"Yes\n";
		}
	}
}

int main(){
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}