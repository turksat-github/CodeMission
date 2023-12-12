/*
the difference between
the sum of the squares of the first ten natural numbers
and
the square of the sum of the first ten natural numbers
*/
let n = 100
var sum1 = Int(0), sum2 = Int(0)
for i in 1...n {
    sum1 += i*i
}
for i in 1...n {
    sum2 += i
}
sum2 *= sum2
print("The difference between the sum of the squares of the first ten natural numbers and the square of the sum of the first ten natural numbers is \(sum2 - sum1)")