t = int(input())
for i in range(t):
    k, x, y = map(int, input().split())
    a, b = min(x, y), max(x, y)
    d = min(a+k-b, b-a)
    if d < k/2:
        print(d-1)
    else:
        print(0) 