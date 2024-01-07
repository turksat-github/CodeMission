/*
n --> n/2 (n is even)
n --> 3n + 1 (n is odd)
Which starting number, under 1000000, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
837799
*/
var a = Int (1)
var b = Int (1000000)
var c = Int (0)
var d = Int (1)
var e = Int (0)
var f = Int (0)
var g = Int (0)

while (true) {
    if (a > 1) {
        if (a % 2 == 0) {
            a /= 2
        }
        else {
            a = 3 * a + 1
        }
        c += 1
    }
    else {
        if (e < c + 1) {
            e = c + 1
            g = f
        }
        d += 1
        a = d
        f = a
        c = 0
    }
    if (c == 0 && a > b) {
        break
    }
}
print (g)