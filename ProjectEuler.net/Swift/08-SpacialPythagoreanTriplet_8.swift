/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a * a + b * b = c * c
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product a * b * c.
*/
var a = Int (1)
var b = Int (1)
var c = Int (1)
var d = Int (1000)
while (a + b + c <= 3 * d) {
    if (a < b - 1) {
        a += 1
    }
    else if (b < c - 1) {
        a = 1
        b += 1
    }
    else {
        a = 1
        b = 1
        c += 1
    }
    if (a * a + b * b == c * c) {
        print ("[\(a + b + c)]   \(a) * \(b) * \(c) = \(a * b * c)")
        if (a + b + c == d) {
            break
        }
    }
}