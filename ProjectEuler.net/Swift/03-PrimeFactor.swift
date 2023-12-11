/*
Find the primes of 600851475143
What is the largest of them
6857
*/
var a = Int (600851475143)
var b = Int (2)
while (b < a) {
    if (((a % b) == 0) && ((a / b) != 1)) {
        a = a / b
    }
    else {
        b = b + 1
    }
}
print ("\(a)")