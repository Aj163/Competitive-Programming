def pos(num, p):
	if num==0:
		return 0
	if num%2==1:
		return p+pos(num-1, p)
	return pos(num//2, p//2)
 
t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    p = 2**(n-1)
    ans = pos(k, p)
    print(ans)