n = int(raw_input())
p = 10**100
for i in range(n):
	num = raw_input()
	k = 1
	c = 0
	while num not in str(k):
		k = (k*2)%p
		c += 1

	print c