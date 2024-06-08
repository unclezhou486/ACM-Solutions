//https://codeforces.com/gym/103688/problem/L
#include <bits/stdc++.h>
using namespace std;

struct Hsr{long long res[2];int len;};
bool eq(Hsr A,Hsr B){return A.res[0]==B.res[0]&&A.res[1]==B.res[1]&&A.len==B.len;}
struct Hash{//0->1 bass
	string s;
    int n;
    vector<vector<long long> > l,r,b;
    int mod[2]={998244353,int(1e9+9)},fac[2]={9527,3960};
	Hsr GhL(int L,int R){//pre
        Hsr C;
        C.len=R-L+1;
        for(int e=0;e<2;e++)C.res[e]=(l[e][R]-l[e][L-1]*b[e][R-L+1]%mod[e]+mod[e])%mod[e];
        return C;
    }
	Hsr GhR(int L,int R){//suf
        Hsr C;
        C.len=R-L+1;
        for(int e=0;e<2;e++)C.res[e]=(r[e][L]-r[e][R+1]*b[e][R-L+1]%mod[e]+mod[e])%mod[e];
        return C;
    }
	Hsr Hplus(Hsr A,Hsr B){
        Hsr C;
        C.len=A.len+B.len;
        for(int e=0;e<2;e++)C.res[e]=(A.res[e]*b[e][B.len]%mod[e]+B.res[e])%mod[e];
        return C;
    }
	int tran(char c){
        if(c>='a')return c-'a'+37;
        if(c>='A')return c-'A'+11;
        return c-'0'+1;
    }
	void init(string &_s){
        s=_s;
        n=s.length();
        b.resize(2,vector<long long>(n+2));
	    l.resize(2,vector<long long>(n+2));
        r.resize(2,vector<long long>(n+2));
	    for(int e=0;e<2;e++)b[e][0]=1,l[e][0]=0,r[e][n+1]=0;
	    for(int e=0;e<2;e++)for(int i=1;i<=n;i++){
            b[e][i]=b[e][i-1]*fac[e]%mod[e];
		    l[e][i]=(l[e][i-1]*fac[e]+tran(s[i-1]))%mod[e];
		    r[e][n+1-i]=(r[e][n+2-i]*fac[e]+tran(s[n-i]))%mod[e];
        }
    }
	//https://codeforces.com/contest/1913/problem/F
	int Ext(int l,int r){//[l,r]fixed_palidrone_extend_mxLen(+1?)
		int L=0,R=min(l,n+1-r);
        while(R-L>1){
            int mid=(L+R)/2;
		    (eq(GhL(l-mid,l-1),GhR(r+1,r+mid)))?L=mid:R=mid;
        }
        return L;
    }
};

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void solve(){
    string s1,s2,s3;
    Hash h1,h2,h3;
    int a,b;
    cin>>s1>>s2;
    s1=s1+s1;
    s3=s2;
    cin>>a>>b;
    int n=s2.size();
    for(int i=0;i<b;i++) s3[i]=s2[b-1-i];
    for(int i=b;i<n;i++) s3[i]=s2[b+n-1-i];
    h1.init(s1),h2.init(s2),h3.init(s3);
    int d=gcd(std::abs(a-b),n);
    auto A=h2.GhL(1,n),B=h3.GhL(1,n);
    for(int i=0;i<n;i+=d){
        auto C=h1.GhL(i+1,i+n);
        if(eq(C,A)||eq(C,B)){
            cout<<"yes\n";
            return;
        }
    }
    cout<<"no\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}