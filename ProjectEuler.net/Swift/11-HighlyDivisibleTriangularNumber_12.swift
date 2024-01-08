/*
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105
On this serial, which is the first value that
have over 500 divisors?
76576500
*/
var a = UInt32 (1)
var b = UInt32 (2)
var c = UInt32 (0)
var d = UInt32 (2)
var e = UInt32 (0)
var f = UInt32 (0)

while (e < 500) {
    a += b
    b += 1
    c = a
    d = 2
    e = 0
    f = UInt32 (Double (c) . squareRoot ())
    while (d <= c) {
        if (c % d == 0) {
            if (f == d) {
                e = e * 2 + 1
                d += 1
                break
            }
            else if (f < d) {
                e *= 2
                d += 1
                break
            }
            else {
                e += 1
            }
        }
        d += 1
    }
}
print (a)