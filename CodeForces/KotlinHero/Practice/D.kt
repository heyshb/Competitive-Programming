fun main(args: Array<String>) {
    val (n, w) = readLine()!!.split(' ').map{it.toInt()}
    val v = readLine()!!.split(' ').map{it.toInt()}
    var ma = w
    var mi = 0
    var S = 0 
    for (i in 0..n-1) {
        S += v[i]
        if (-S + w < ma) {
            ma = -S + w
        }
        if (-S > mi) {
            mi = -S
        }
    }
    if (mi > ma) {
        println(0)
    } else {
        println(ma - mi + 1)
    }
}