'''
find the smallest positive number that is evenly divisible (no remainder) by all of the numbers from 1 to 20
232792560
'''
n = 20
b = 0
a = 10
while b == 0 :
    b = 1
    for i in range (2, n + 1) :
        if (a % i) != 0 :
            b = 0
            break
    a += 10
print (a - 10)
