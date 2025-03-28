#include <bits/stdc++.h>

using namespace std;

int ma[16][16][16][16][16];
int cntt[16][16][16][16][16];
bool viss[16][16][16][16][16];

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> cnt(n+10);
	vector<vector<int> > se(6);
	vector<vector<int> > a(n+10,vector<int>(6) ) ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int q=1;q<=n;q++){
					for(int w=1;w<=n;w++){
						ma[i][j][k][q][w]=0;
						viss[i][j][k][q][w]=0;
						cntt[i][j][k][q][w]=0;
					}
				}
			}
		}
	}
	for(int i=1;i<=5;i++){
		// int x;
		// cin>>x;
		cin>>cnt[i];
		for(int j=1;j<=cnt[i];j++){
			// cin>>a[i][j];
			int x;
			cin>>x;
			se[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<int> > vec;
	// map<vector<int>,int> ma;
	vector<int> vis(n+10);
	vector<int> vecc(5);
	for(auto a1:se[1]){
		vis[a1]=1;
		vecc[0]=a1;
		for(auto a2:se[2]){
			if(vis[a2]) continue;
			vis[a2]=1;
			vecc[1]=a2;
			for(auto a3:se[3]){
				if(vis[a3]) continue;
				vis[a3]=1;
				vecc[2]=a3;
				// if(a3==a2||a3==a1) continue;
				for(auto a4:se[4]){
					// if(a4==a3||a4==a2||a4==a1)
					if(vis[a4]) continue;
					vis[a4]=1;
					vecc[3]=a4;
					for(auto a5:se[5]){
						if(vis[a5]) continue;
						vis[a5]=1;
						vecc[4]=a5;
						vector<int> res;
						res=vecc;
						sort(res.begin(),res.end());
						if(!viss[res[0]][res[1]][res[2]][res[3]][res[4]]){
							vec.push_back(res);
						}
						viss[res[0]][res[1]][res[2]][res[3]][res[4]]=1;
						cntt[res[0]][res[1]][res[2]][res[3]][res[4]]+=1;
						vis[a5]=0;
					}
					vis[a4]=0;
				}
				vis[a3]=0;
			}
			vis[a2]=0;
		}
		vis[a1]=0;
	}
	// cout<<vec.size()<<'\n';
	for(auto veccc:vec){
		vector<int> res;
		res=veccc;
		sort(res.begin(),res.end());
		int cnt=0;
		do{
			bool flag=true;
			for(int i=0;i<5;i++){
				if(!a[res[i]][i+1]){
					flag=false;
				}
			}
			if(flag) cnt+=1;
		}while(next_permutation(res.begin(),res.end()));
		ma[veccc[0]][veccc[1]][veccc[2]][veccc[3]][veccc[4]]=cnt*cntt[veccc[0]][veccc[1]][veccc[2]][veccc[3]][veccc[4]];
	}
	vector<int> bann(n+10);
	vector<int> bana(n+10);
	for(int i=1;i<=q;i++){
		int bancnt=0;
		long long cnt=0;
		cin>>bancnt;
		for(int j=1;j<=bancnt;j++){
			cin>>bana[j];
			bann[bana[j]]=1;
		}
		for(auto veccc:vec){
			bool flag=true;
			for(auto x:veccc){
				if(bann[x]){
					flag=false;
					break;
				}
			}
			if(flag){
				cnt+=ma[veccc[0]][veccc[1]][veccc[2]][veccc[3]][veccc[4]];
			}
		}
		for(int j=1;j<=bancnt;j++){
			bann[bana[j]]=0;
		}
		cout<<cnt<<'\n';
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