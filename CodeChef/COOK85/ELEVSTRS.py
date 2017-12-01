t = int(input())
for i in range(t):
    n, v2, v1 = map(int, input().split())
    #print(v2*2*n , v1*(2**0.5)*n)
    if v2*2 <= v1*(2**0.5):
        print('Elevator')
    else:
        print('Stairs') 