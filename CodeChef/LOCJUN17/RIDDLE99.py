import math
 
t=int(input())
for i in range(t):
	a, b, m = map(int, input().split())
	print(math.floor(b/m)-math.ceil(a/m)+1)  