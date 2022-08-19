n = int(input())

for item in range(n+1):
    count = 0
    i = int(input())
    a = input()
    b = input()
    for k in range(i):
        if a[k] != b[k]:
            count += 1 # -*- coding: latin-1 -*-
            
    if (a.count('1') % 2 and  not (count % 2)) or ( not (a.count('1')) % 2 and count % 2):
        print(1)
    else:
        print(0)