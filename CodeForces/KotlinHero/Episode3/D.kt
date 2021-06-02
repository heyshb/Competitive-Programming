import kotlin.system.exitProcess
//exitProcess(0)

fun rd() = readLine()!!
fun rdInt() = rd().toInt()
fun rdList() = rd().split(' ').map{it.toInt()}.toMutableList()
var arr = Array(500000){0}
var ans1 = mutableListOf<Int>()

fun main(args: Array<String>) {
    val T = rdInt()
    repeat(T) {
        var (N, K) = rdList()
        var a = rdList()
        var ans = Array(N){0}
        var tmpans = Array(N){0}
        val mp = mutableMapOf<Int, Int>()
        for (i in 0..N-1) {
            mp[a[i]] = i
        }
        var b = a.sorted().toTypedArray()
        for (i in N-2 downTo 0) {
            val target = b[N - 1] - (N - 1 - i)
            var delta = target - b[i]
            if (delta > K) {
                delta = K
            }
            tmpans[i] = delta
            K -= delta
        }
        if (K > 0) {
            for (i in 0..N-1) {
                tmpans[i] += K / N
                if ((N - i) <= K % N) {
                    tmpans[i] += 1
                }
            }
        }
        for (i in 0..N-1) {
            ans[mp[b[i]]!!] = tmpans[i]
        }
        //println(b[N-1] + tmpans[N-1])
        println(ans.joinToString(" "))
    }
}