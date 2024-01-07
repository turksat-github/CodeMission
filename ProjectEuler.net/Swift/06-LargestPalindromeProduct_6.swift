/*
Find the largest palindrome made from the product of two 3-digit numbers.
*/
var a = Int (999 * 999)
var b = Int (1)
while (a > 100 * 1000) {
    if (a % 10) == (Int(a / 100000)) {
        if (Int((a % 100) / 10)) == ((Int(a / 10000)) % 10) {
            if (Int((a % 1000) / 100)) == ((Int(a / 1000)) % 10) {
                for i in stride(from: 999, through: 100, by: -1) {
                    if (a % i) == 0 {
                        if ((Int(a / i)) < 1000) && ((Int(a / i)) > 100) {
                            print (a)
                            b = 0
                            break
                        }
                    }
                }
                if (b == 0) {
                    break
                }
            }
        }
    }
    a -= 1
}