'''
Find the primes of 600851475143
What is the largest of them
6857
'''
a = 600851475143
b = 2
result = b
while (b < a) :
    if (((a % b) == 0) and ((a / b) != 1)) :
        a = (a / b)
        result = b
    else :
        b = b + 1
print (b)