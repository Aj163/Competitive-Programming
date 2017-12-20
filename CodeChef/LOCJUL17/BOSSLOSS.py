import math
 
t = int(input())
for z in range(t):
    n, m = map(int, input().split())
    ans = (8*m + 1)**0.5 -1
    ans/=2
    ans = math.ceil(ans)
    
    if ans>n:
        print(-1)
    else:
        print(ans) 