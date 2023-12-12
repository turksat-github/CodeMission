'''
the difference between
the sum of the squares of the first ten natural numbers
and
the square of the sum of the first ten natural numbers
'''
sum1 = 0
for i in range(101):
    sum1 = sum1 + (i * i)
sum2 = 0
for j in range(101):
    sum2 = sum2 + j
sum2 = sum2 * sum2
print (sum2 - sum1)