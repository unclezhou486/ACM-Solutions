n,m,p=map(int,input().split())
mod=p
def qmi(a,b):
    res=1
    while b:
        if(b&1): res=res*a%p
        a=a*a%p
        b>>=1
    return res
zuhe=[[0 for i in range(n+1)]for j in range(n+1)]
#print(zuhe)
zuhe[0][0]=1
for i in range(1,n+1):
    for j in range(0,i+1):
        zuhe[i][j]=zuhe[i-1][j]
        if j-1>=0: zuhe[i][j]=(zuhe[i][j]+zuhe[i-1][j-1])%p
ans=0
toi=1
for i in range(1,n+1):
    pmn=qmi(2,(m-1)*(n-i))
    toi=toi *2 % mod
    ans=(ans+((qmi((toi-1+mod)%mod,m-1)*zuhe[n][i]%mod)*pmn%mod))%mod
    if i<=m-1:
        x=0
        for j in range(i+1):
            if j%2==0:
                x+=qmi((toi - 1 - j + mod) % mod, m - 1) * zuhe[i][j] % mod
            else:
                x-=qmi((toi - 1 - j + mod) % mod, m - 1) * zuhe[i][j] % mod

        x=(x%mod+mod)%mod
        ans=(ans-(zuhe[n][i]*x%mod)*pmn%mod+mod)%mod
if m == 1:
    ans = qmi(2, n) - n - 1
ans %= mod
print(ans)
# 4987 1234 2132142