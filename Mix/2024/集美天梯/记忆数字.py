a=input()
res=0
for i in a:
    if('a'<=i<='z' or 'A'<=i<='Z'):res+=1
    else:
        if res:
            print(res%10,end='')
        res=0
if(res):print(res%10,end='')