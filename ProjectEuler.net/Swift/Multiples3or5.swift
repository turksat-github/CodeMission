/*
if the number is divisible by 3 and 5
sum all of the correct numbers until 1000
*/
var a = Int (3)
var b = Int (5)
var n = Int (1000)
var sum = Int (0)
for i in stride (from:1, to:n, by: 1) {
    if (((i % a) == 0) || ((i % b) == 0)) {
        sum += i
    }
}
print ("\(sum)")