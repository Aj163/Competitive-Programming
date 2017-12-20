import math
 
def f(k):
	a=2**(int(math.log(k)/math.log(2)))
	if a==k:
		return 'a'
	if f(a-k+a)=='a':
		return 'c'
	return 'a'
 
t=int(input())
for i in range(t):
	k=int(input())
	print(f(k)) 