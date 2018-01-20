t = int(input())
for i in range(t):
	n = int(input())
	a=[int(j) for j in input().split()]
	s=a[0]
	for j in range(1, n):
		s|=a[j]
	print(s)