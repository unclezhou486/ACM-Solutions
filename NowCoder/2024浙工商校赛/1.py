t=int(input())
for i in range(t):
	s=input()
	ans=''
	j=0
	while(j<len(s)):
	# for j in range(len(s)):
		if j+2<len(s):
			if(s[j]+s[j+1]+s[j+2]=="ljl"):
				ans=ans+"ncljr"
				j+=3
				continue
		ans=ans+s[j]
		j+=1
	print(ans)
