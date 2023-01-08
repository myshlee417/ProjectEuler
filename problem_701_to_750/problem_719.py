import math
import tqdm

N = 10**12
num_square = 0

def split_number(n):
    tmp_split_n = []
    tmp_num_digit = 0
    while n>0:
        tmp_split_n.append(n%10)
        n //= 10
        tmp_num_digit += 1
    return tmp_split_n, tmp_num_digit


for n in tqdm.tqdm(range(1, int(math.sqrt(N)+1))):
    n_square = n**2
    split_n, num_digit = split_number(n_square)

#    print(split_n)
#    print(num_digit)

    cases = []
    for k in range(2**(num_digit-1)-1):
        case = []
        case.append(0)
        tmp_k = k
        for j in range(num_digit-1):
            case.append(tmp_k%2)
            tmp_k //= 2
        cases.append(case)

#    print(cases)

    for i in cases:
        value = 0
        multiply = 1
        for j in range(len(split_n)):
            if i[j]==0:
                multiply = 1
                value += split_n[j] * multiply
            else:
                multiply *= 10
                value += split_n[j] * multiply
        if value==n:
            num_square+=n_square
            break
print(num_square)
