/*
find the smallest positive number that is evenly divisible (no remainder) by all of the numbers from 1 to 20
*/
let n = 20
var a = Bool (true)
var b = Int (10)
while (a) {
    a = false
    for i in 2...n {
        if (b % i != 0) {
            a = true
            break
        }
    }
    b += 10
}
print (b - 10)