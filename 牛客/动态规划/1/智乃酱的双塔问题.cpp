#include<bits/stdc++.h>
using namespace std;
const int MAX_MAT = 2;
const long long mod = 1e9 + 7;
const int N=1e5+10;
struct Mat
{
	long long a[MAX_MAT][MAX_MAT];
	Mat()
	{
		for (int i = 0; i < MAX_MAT; ++i)
		{
			for (int j = 0; j < MAX_MAT; ++j)
			{
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < MAX_MAT; ++i)
		{
			a[i][i] = 1;
		}
	}
	Mat(long long a1, long long a2, long long a3, long long a4)
	{
		a[0][0] = a1;
		a[0][1] = a2;
		a[1][0] = a3;
		a[1][1] = a4;
	}
};
long long quickpow(long long x, long long y, long long MOD = mod)
{
	long long ans = 1;
	while (y)
	{
		if (y & 1)
		{
			ans = (x * ans) % MOD;
		}
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ans;
}
long long A[MAX_MAT][MAX_MAT << 1];
long long get_inv(long long x)
{
	return quickpow(x, mod - 2, mod);
}
void row_minus(int a, int b, long long k)
{
	for (int i = 0; i < 2 * MAX_MAT; ++i)
	{
		A[a][i] = (A[a][i] - A[b][i] * k % mod) % mod;
		if (A[a][i] < 0)A[a][i] += mod;
	}
	return;
}
void row_multiplies(int a, long long k)
{
	for (int i = 0; i < 2 * MAX_MAT; ++i)
	{
		A[a][i] = (A[a][i] * k) % mod;
	}
	return;
}
void row_swap(int a, int b)
{
	for (int i = 0; i < 2 * MAX_MAT; ++i)
	{
		swap(A[a][i], A[b][i]);
	}
}
Mat getinv(Mat x)
{
	memset(A, 0, sizeof(A));
	for (int i = 0; i < MAX_MAT; ++i)
	{
		for (int j = 0; j < MAX_MAT; ++j)
		{
			A[i][j] = x.a[i][j];
			A[i][MAX_MAT + j] = i == j;
		}
	}
	for (int i = 0; i < MAX_MAT; ++i)
	{
		if (!A[i][i])
		{
			for (int j = i + 1; j < MAX_MAT; ++j)
			{
				if (A[j][i])
				{
					row_swap(i, j);
					break;
				}
			}
		}
		row_multiplies(i, get_inv(A[i][i]));
		for (int j = i + 1; j < MAX_MAT; ++j)
		{
			row_minus(j, i, A[j][i]);
		}
	}
	for (int i = MAX_MAT - 1; i >= 0; --i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			row_minus(j, i, A[j][i]);
		}
	}
	Mat ret;
	for (int i = 0; i < MAX_MAT; ++i)
	{
		for (int j = 0; j < MAX_MAT; ++j)
		{
			ret.a[i][j] = A[i][MAX_MAT + j];
		}
	}
	return ret;
}
Mat operator * (Mat x, Mat y)
{
	Mat c;
	for (int i = 0; i < MAX_MAT; ++i) {
		for (int j = 0; j < MAX_MAT; ++j) {
			c.a[i][j] = 0;
		}
	}
	for (int i = 0; i < MAX_MAT; ++i) {
		for (int j = 0; j < MAX_MAT; ++j) {
			for (int k = 0; k < MAX_MAT; ++k) {
				c.a[i][j] = (c.a[i][j] + x.a[i][k] * y.a[k][j] % mod) % mod;
			}
		}
	}
	return c;
}

Mat ma1(1,1,0,1),ma2(1,0,1,1);
Mat s[N];
char ch;
int n,m,hs,ht,ps,pt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    s[0]=Mat(1,0,0,1);
    for(int i=1;i<n;i++){
        cin>>ch;
        if(ch=='/'){
            s[i]=s[i-1]*ma1;
        }
        else s[i]=s[i-1]*ma2;
    }
    while(m--){
        cin>>hs>>ht>>ps>>pt;
        Mat ans=getinv(s[hs-1])*s[ht-1];
        cout<<ans.a[ps][pt]<<'\n';
    }
}
