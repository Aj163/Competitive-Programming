n = int(input())

a = [int(i) for i in raw_input().split()]
m = {}
m[a[0]] = 1
sums = a[0]
ans = 0

for i in range(1, n):
	ans += i*a[i] - sums
	try:
		ans -= m[a[i]-1]
	except:
		pass
	try:
		ans += m[a[i]+1]
	except:
		pass

	sums += a[i]
	try:
		m[a[i]] += 1
	except:
		m[a[i]] = 1

print(ans)