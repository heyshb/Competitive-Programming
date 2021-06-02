fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    val s = readLine()!!
    var node = 0
    var ans = 0
    while (node < N) {
        if (s[node] != 'x') {
            node += 1
            continue
        }
        var nxt = node
        /* 
        while (nxt + 1 < N) {
            if (s[nxt + 1] != 'x') {
                break
            }
            nxt += 1
        }
        */
        while ((nxt + 1 < N) && (s[nxt + 1] == 'x')) {
            nxt += 1
        }
        if (nxt - node >= 2) {
            ans += nxt - node - 1
        }
        node = nxt + 1
    }
    println(ans)
}