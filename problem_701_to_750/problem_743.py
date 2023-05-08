import math
# from tqdm import tqdm

def combination(n, r):
    ret = 1
    for m in range(r+1, n+1):
        ret *= m
    for div in range(1, n-r+1):
        ret /= div
    return ret

# print(combination(4, 3))

# k = 4
# n = 20
k = 100000000
n = 10000000000000000
mod_value = 1000000007
repeat_window = n/k

sum_window = 0
param = 1
for num_two in range(0, math.floor(k/2)+1):
# for num_two in tqdm(range(0, math.floor(k/2)+1)):
    num_one = k-num_two*2
    num_zero = num_two

#    sum_window += math.factorial(k)/math.factorial(num_two)/math.factorial(num_one)/math.factorial(num_zero) * 2 **(repeat_window*num_one)
#    sum_window += combination(k, num_two)*combination(k-num_two, num_one) * 2 **(repeat_window*num_one)

    sum_window += param * pow(2, int(repeat_window*num_one), mod_value)
    sum_window %= mod_value

    param *= num_one*(num_one-1)*pow(pow(num_two+1, 2), -1, mod_value)
    param %= mod_value

    print(str(num_zero)+', '+str(num_one)+', '+str(num_two))
    print(sum_window)
