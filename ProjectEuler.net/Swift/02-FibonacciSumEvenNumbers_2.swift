/*
sum of the even-valued terms of
Fibonacci sequence under four million
1, [2], 3, 5, [8], 13, 21, [34], 55, 89, [144]...
4613730
*/
var a = Int (1)
var b = Int (2)
var n = Int (4000000)
var sum = Int (0)
while (a < n) {
    if (b % 2 == 0) {
        sum += b
    }
    let c = a
    a = b
    b += c
}
print ("\(sum)")