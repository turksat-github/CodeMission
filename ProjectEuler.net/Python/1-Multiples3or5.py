'''
if the number is divisible by 3 and 5
sum all of the correct numbers until 1000
'''
a = 3
b = 5
n = 1000
sum = 0
for i in range (n):
    if (((i % a) == 0) or ((i % b) == 0)):
        sum = sum + i
print (sum)