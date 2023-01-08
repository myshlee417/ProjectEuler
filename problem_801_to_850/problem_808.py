import math
current_num = 0
num = 50
p = 4
sum_value = 0

def is_prime(n):
    for k in range(2, int(math.sqrt(n))+1):
        if n%k == 0:
            return False
    return True

def is_palindrome(n):
    return str(n) == str(n)[::-1]

while current_num<num:
    if is_prime(p):
        reverse_value = int(str(p*p)[::-1])
        q = int(math.sqrt(reverse_value))
        if reverse_value != p*p and reverse_value == q*q and is_prime(q):
            current_num += 1
            sum_value += p*p
            print("Num "+str(current_num)+": "+str(p*p))
    p+=1

print(sum_value)
