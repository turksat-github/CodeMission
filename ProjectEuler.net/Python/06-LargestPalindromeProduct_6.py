'''
Find the largest palindrome made from the product of two 3-digit numbers.
'''
c = 999 * 999
while c > (100 * 1000) :
    if (c % 10) == ((int)(c / 100000)) :
        if ((int)((c % 100) / 10)) == ((int)(c / 10000)) % 10 :
            if ((int)((c % 1000) / 100)) == ((int)(c / 1000)) % 10 :
                for i in range (999, 99, -1) :
                    if (c % i) == 0 :
                        if ((int)(c / i)) < 1000 and ((int)(c / i)) > 100 :
                            print (c)
                            exit ()
    c -= 1