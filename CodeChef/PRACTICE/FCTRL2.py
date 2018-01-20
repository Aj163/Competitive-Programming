t=int(input())
for i in range(t):
	n = int(input())
	ans=1
	for j in range(1, n+1):
		ans*=j
	print(ans)