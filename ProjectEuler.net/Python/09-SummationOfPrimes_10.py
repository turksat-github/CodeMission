'''
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
142913828922
'''
import math
a = 3
b = 15#2, 3, 5, 7, 11, 13 already known
c = 2000000
d = math.sqrt (b) + 2
total = 41
#print ("2\n3\n5\n7\n11\n13")
while b < c :
    if a > d :
        total += b
        #print (b)
        b += 2
        a = 3
        d = math.sqrt (b) + 2
    elif b % a == 0 :
        b += 2
        a = 3
    else :
        a += 2
print (total)