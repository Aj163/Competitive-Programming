t = int(input())
for i in range(t):
    a = [int(j) for j in input().split()]
    l = len(a)
    if a.count(l-1) == 0:
        print(max(a))
    else:
        a.remove(l-1)
        print(max(a)) 