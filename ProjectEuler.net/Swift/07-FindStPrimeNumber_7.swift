/*
Find the 10001st prime number.
104743 is the 10001st prime number.
*/
var a = Int (3)
var b = Int (15)
var c = Int (6) //2, 3, 5, 7, 11, 13
var d = Int (10001)
var e = Int (3)
//print ("2\n3\n5\n7\n11\n13")
while (c < d) {
    while (true) {
        if (a > e) {
            if (e == 3) {
                break
            }
            //print (b)
            c += 1
            break
        }
        else if (b % a == 0) {
            break
        }
        else {
            a += 2
        }
    }
    b += 2
    e = Int (Double (b) . squareRoot ())
    a = 3
}
print (b - 2)