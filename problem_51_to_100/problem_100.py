import math
# n = 5
n = 1000000000000
while True:
    k = int(math.sqrt(n*(n-1)/2)) + 1
#     print("n: "+str(n)+", k: "+str(k))
    if 2*k*(k-1)==n*(n-1):
        print(k)
        break
    n+=1
