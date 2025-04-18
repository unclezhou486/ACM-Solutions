#include <bits/stdc++.h>

using namespace std;

struct SegmentTree{
	vector<int> num;
	int n;
	void init(int n){
		this->n=n;
		num.assign((n+10)<<2,0);
	}
	void update(int l,int r,int k,int x,int tr){
		if(l==r){
			num[tr]=x;
			return;
		}
		int mid=(l+r)>>1;
		if(k<=mid) update(l,mid,k,x,tr<<1);
		if(mid<k) update(mid+1,r,k,x,tr<<1|1);
		num[tr]=max(num[tr<<1],num[tr<<1|1]);
	}
	int query(int l,int r,int x,int tr){
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(num[tr<<1]>=x){
			return query(l,mid,x,tr<<1);
		}
		else if(num[tr<<1|1]>=x){
			return query(mid+1,r,x,tr<<1|1);
		}
		else{
			return -1;
		}
	}
}sg[2];

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	sg[0].init(n);
	sg[1].init(n);
	vector<int> lenhead(n+10),lentail(n+10),ss(n+10);
	char la=s[0];
	int cnt=0;
	int laid=-1;
	for(int i=0;i<s.size();i++){
		char ch=s[i];
		if(ch==la){
			cnt+=1;
		}
		else{
			if(la=='0'){
				sg[0].update(0,n-1,laid+1,cnt,1);
				lenhead[laid+1]=cnt;
				lentail[i-1]=cnt;
				ss[i-1]=0;
				ss[laid+1]=0;
			}
			else{
				sg[1].update(0,n-1,laid+1,cnt,1);
				lenhead[laid+1]=cnt;
				lentail[i-1]=cnt;
				ss[i-1]=1;
				ss[laid+1]=1;
			}
			la=ch;
			laid=i-1;
			cnt=1;
		}
	}
	if(cnt){
		if(la=='0'){
			// se[0].insert({cnt,laid+1});
			sg[0].update(0,n-1,laid+1,cnt,1);	
			lenhead[laid+1]=cnt;
			lentail[n-1]=cnt;
			ss[n-1]=0;
			ss[laid+1]=0;
		}
		else{
			sg[1].update(0,n-1,laid+1,cnt,1);
			// se[1].insert({cnt,laid+1});
			lenhead[laid+1]=cnt;
			lentail[n-1]=cnt;
			ss[n-1]=1;
			ss[laid+1]=1;
		}
		cnt=0;
	}
	int q;
	cin>>q;
	auto merge = [&](int tail1,int head2) -> void{
		int op=ss[tail1];
		int len1=lentail[tail1],len2=lenhead[head2];
		int head1=tail1-len1+1,tail2=head2+len2-1;
		sg[op].update(0,n-1,head1,0,1);
		sg[op].update(0,n-1,head2,0,1);
		// se[op].erase({len1,head1});
		// se[op].erase({len2,head2});
		lenhead[head1]=len1+len2;
		lentail[tail2]=len1+len2;
		sg[op].update(0,n-1,head1,len1+len2,1);
		// se[op].insert({len1+len2,head1});
	};
	while(q--){
		int op,k;
		cin>>op>>k;
		// auto it = se[op].lower_bound({k,0});
		int head=sg[op].query(0,n-1,k,1);
		if(head==-1){
			cout<<-1<<'\n';
			continue;
		}
		int len=lenhead[head];
		// auto [len,head]=*it;
		cout<<head+1<<'\n';
		int tail=head+len-1;
		// se[op].erase(it);
		sg[op].update(0,n-1,head,0,1);
		lenhead[head]=k;
		lentail[head+k-1]=k;
		ss[head]=op^1;
		ss[head+k-1]=op^1;
		sg[op^1].update(0,n-1,head,k,1);
		// se[op^1].insert({k,head});
		if(len-k>0){
			ss[head+k]=op;
			sg[op].update(0,n-1,head+k,len-k,1);
			// se[op].insert({len-k,head+k});
			lenhead[head+k]=len-k;
			lentail[tail]=len-k;
		}
		if(head>0&&ss[head]==ss[head-1]){
			merge(head-1,head);
		}
		if(head+k<n&&ss[head+k]==ss[head+k-1]){
			merge(head+k-1,head+k);
		}
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