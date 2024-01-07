'''
n --> n/2 (n is even)
n --> 3n + 1 (n is odd)
Which starting number, under 1000000, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
837799
'''
a = 1
b = 1000000
c = 0
d = 1
e = 0
f = 0
g = 0
while True :
    if a > 1 :
        if a % 2 == 0 :
            a /= 2
        else :
            a = 3 * a + 1
        c += 1
    else :
        if e < c + 1 :
            e = c + 1
            g = f
        d += 1
        a = d
        f = a
        c = 0
    if c == 0 and a > b :
        break
print (g)