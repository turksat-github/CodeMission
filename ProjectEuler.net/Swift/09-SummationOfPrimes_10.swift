/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
142913828922
*/
var a = Int (3)
var b = Int (15)//2, 3, 5, 7, 11, 13 already known
var c = Int (2000000)
var d = Int (Double (b) . squareRoot ()) + 2
var total = Int64 (41)//print ("2\n3\n5\n7\n11\n13")

while (b < c) {
    if (a > d) {
        total += Int64(b)//print (b)
        b += 2
        d = Int (Double (b) . squareRoot ()) + 2
        a = 3
    }
    else if (b % a == 0) {
        b += 2
        a = 3
    }
    else {
        a += 2
    }
}
print (total)