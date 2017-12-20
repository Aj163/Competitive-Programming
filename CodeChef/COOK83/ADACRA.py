import re
 
t=int(input())
for i in range(t):
    s=input()
    u=len(re.findall("U+", s))
    d=len(re.findall("D+", s))
    print(min(u, d)) 