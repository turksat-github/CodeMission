'''
Find the 10001st prime number.
104743 is the 10001st prime number.
'''
a = 2
b = 2
c = 0
d = 10001
while c < d :
    while True :
        if a == b :
            c += 1
            break
        else :
            if b % a == 0 :
                break
            else :
                a += 1
    a = 2
    b += 1
print (b-1)