fun rd() = readLine()!!
fun rdInt() = rd().toInt()
fun rdList() = rd().split(' ').map{it.toInt()}.toMutableList()
var arr = Array(500000){0}
var ans1 = mutableListOf<Int>()
var e = Array(0, {ArrayList<Int>()})

fun main(args: Array<String>) {
    val T = rdInt()
    repeat(T) {
        val (N, K) = rdList()
        var d = Array(N + 1){0}
        var e = Array(N + 1, {ArrayList<Int>()})
        for (i in 1..N-1) {
            val (u, v) = rdList()
            d[u] += 1
            d[v] += 1
            e[u].add(v)
            e[v].add(u)
        }
        var del = Array(N + 1){false}
        var q = Array(N + 10){0}
        var head = 1
        var tail = 0
        for (i in 1..N) {
            if (d[i] == 1) {
                tail += 1
                q[tail] = i
            }
        }
        if (K == 1) {
            println("Yes")
            println(1)
            println(1)
        } else if (tail < K) {
            println("No")
        } else {
            while(tail - head + 1 > K) {
                var now = q[head]
                head += 1
                for (t in e[now]) {
                    if (del[t]) {
                        continue
                    }
                    d[t] -= 1
                    if (d[t] <= 1) {
                        tail += 1
                        q[tail] = t
                    }
                }
                del[now] = true
            }
            println("Yes")
            var ans = mutableListOf<Int>()
            for (i in 1..N) {
                if (!del[i]) {
                    ans.add(i)
                }
            }
            println(ans.size)
            println(ans.joinToString(" "))
        }
    }
}