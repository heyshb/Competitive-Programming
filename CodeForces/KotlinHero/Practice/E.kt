fun main(args: Array<String>) {
    val (N, K) = readLine()!!.split(' ').map{it.toInt()}
    val r = readLine()!!.split(' ').map{it.toInt()}
    val rs = r.sorted()
    val mp = mutableMapOf<Int, Int>()
    val ans = Array<Int>(N, {0})
    for (i in 0..N-1) {
        if (i == 0 || rs[i] != rs[i - 1]) {
            mp[rs[i]] = i
        }
    }
    for (i in 0..N-1) {
        ans[i] = mp[r[i]]!!
    }

    for (i in 1..K) {
        val (x, y) = readLine()!!.split(' ').map{it.toInt()-1}
        if (r[x] > r[y]) {
            ans[x] -= 1
        }
        if (r[y] > r[x]) {
            ans[y] -= 1
        }
    }
    println(ans.joinToString(" "))
}