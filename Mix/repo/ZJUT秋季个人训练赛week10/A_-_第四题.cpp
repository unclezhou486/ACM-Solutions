#include <bits/stdc++.h>

using namespace std;

constexpr int N=2e6+20;

int q;

struct node{
	int op,t,x,y;
}qu[N];

int val[N],valx[N];

struct line{
	int x,id;
	bool operator < (const line &a) const {
		return x<a.x;
	}
};

struct BIT{
	int n;
	int b[N];
	void init(int n){
		this->n=n;
		memset(b,0,sizeof b);
	}
	int lowbit(int x){
		return x&-x;
	}
	void add(int k,int x){
		for(;k<=n;k+=lowbit(k)) b[k]+=x;
	}
	int query(int x){
		int res=0;
		for(;x;x-=lowbit(x)) res+=b[x];
		return res;
	}
	int sum(int l,int r){
		// if(l==0) return query(r);
		return query(r)-query(l-1);
	}
}bit1,bit2;

int check(int x){
	return 2*min(bit1.sum(1,x),bit2.sum(x,q));
}

struct seg{
	int sum[N<<2];
	void update(int x,int k,int tr=1,int l=1,int r=q){
		if(l==r){
			sum[tr]=k;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid) update(x,k,tr<<1,l,mid);
		if(mid<x) update(x,k,tr<<1|1,mid+1,r);
		sum[tr]=sum[tr<<1]+sum[tr<<1|1]; 
	}
	int find(int k,int tr=1,int l=1,int r=q){
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(sum[tr<<1]>=k){
			return find(k,tr<<1,l,mid);
		}
		else{
			return find(k-sum[tr<<1],tr<<1|1,mid+1,r);
		}
	}
	int query(int l,int r,int tr=1,int x=1,int y=q){
		if(x<=l&&r<=y){
			return sum[tr];
		}
		int mid=(x+y)>>1;
		int res=0;
		if(l<=mid) res+=query(l,r,tr<<1,x,mid);
		if(mid<r) res+=query(l,r,tr<<1|1,mid+1,y);
		return res; 
	}
}seg;

void solve(){
	cin>>q;
	vector<line> b;
	for(int i=1;i<=q;i++){
		int op,t,x,y;
		cin>>op;
		if(op==1){
			cin>>t>>x>>y;
			b.push_back((line){x,i});
		}
		else{
			cin>>t;
		}
		qu[i]=(node){op,t,x,y};
	}
	bit1.init(q),bit2.init(q);
	sort(b.begin(),b.end());
	int idx=1;
	val[b[0].id]=idx;
	valx[idx]=b[0].x;
	for(int i=1;i<b.size();i++){
		if(b[i].x!=b[i-1].x) idx++;
		val[b[i].id]=idx;
		valx[idx]=b[i].x;
	}
	int num1=0,num2=0;
	int mid=1;
	// for(int i=1;i<=idx;i++){
		// cout<<valx[i]<<" \n"[i==idx];
	// }
	for(int i=1;i<=q;i++){
		if(qu[i].op==1){
			seg.update(val[i],1);
			if(qu[i].t==0){
				num1++;
				// seg.update(val[i],1);
				bit1.add(val[i],qu[i].y);
			}
			else{
				num2++;
				// seg.update(val[i],1);
				bit2.add(val[i],qu[i].y);
			}
		}
		else{
			int x=qu[i].t;
			seg.update(val[x],0);
			if(qu[x].t==0){
				num1--;
				bit1.add(val[x],-qu[x].y);
			}
			else{
				num2--;
				bit2.add(val[x],-qu[x].y);
			}
		}
		if(!num1||!num2){
			cout<<"Peace\n";
		}
		else{
			int xx=seg.query(1,mid);
			int num=seg.sum[1];
			int mid1=mid;
			if(xx>1) mid1=seg.find(xx-1);
			int mid2=mid;
			if(xx<num) mid2=seg.find(xx+1);
			if(check(mid)<check(mid1)) mid=mid1;
			if(check(mid)<check(mid2)) mid=mid2;
			while(mid>1&&check(mid)<check(mid-1)) mid-=1;
			while(mid<idx&&check(mid)<=check(mid+1)) mid+=1;
			// for(int i=1;i<=idx;i++){
			// 	cout<<check(i)<<" \n"[i==idx];
			// }
			// cout<<mid<<'\n';
			// cout<<check(3)<<'\n';
			cout<<valx[mid]<<' '<<check(mid)<<'\n';
		}
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