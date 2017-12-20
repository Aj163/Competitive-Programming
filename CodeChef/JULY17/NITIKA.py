def cap(c):
    if ord(c)>94:
        c = chr(ord(c)-32)
    return c
 
t=int(input())
for i in range(t):
    a=input().split()
    
    a[len(a)-1] = list(a[len(a)-1])
    for i in range(len(a[len(a)-1])):
        if ord(a[len(a)-1][i])<94:
            a[len(a)-1][i] = chr(ord(a[len(a)-1][i])+32)
    #print(a)
    if ord(a[len(a)-1][0])>94:
        a[len(a)-1][0] = cap(a[len(a)-1][0])
        
    if len(a)==1:
        print(''.join(a[0]))
    elif len(a)==2:
        a[0] = list(a[0])
        print(cap(a[0][0]), end='. ')
        print(''.join(a[1]))
    else:
        a[0] = list(a[0])
        a[1] = list(a[1])
        print(cap(a[0][0]), end='. ')
        print(cap(a[1][0]), end='. ')
        print(''.join(a[2])) 