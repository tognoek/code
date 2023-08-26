n = float(input())
a = int(n) - float(n) 
if (abs(a)*10) >= 5: 
    print(int(n) + 1 if int(n) >=0 else int(n) - 1)
else: print(int(n))