'''
sum of the even-valued terms of
Fibonacci sequence under four million
1, [2], 3, 5, [8], 13, 21, [34], 55, 89, [144]...
4613730
'''
a = 3
b = 5
n = 4000000
sum = 0
while (b < n) :
    if ((b % 2) == 0) :
        sum += b
    c = a
    a = b
    b += c
print (sum)