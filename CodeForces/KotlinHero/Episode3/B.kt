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
        var lst = mutableListOf<Int>()
        val N = rdInt()
        repeat(N) {
            var (a, b) = rdList()
            b += 1
            lst.add(2 * a)
            lst.add(2 * b + 1)
        }
        val rt = lst.sorted()
        var cnt = 0
        var ans = -1
        for (i in 0..(2*N-1)) {
            if (rt[i] % 2 == 0) {
                cnt += 1
            } else {
                cnt -= 1
            }
            if (i == 2 * N - 1 || rt[i] / 2 != rt[i + 1] / 2) {
                if (cnt == 1) {
                    ans = rt[i] / 2
                    break
                }
            }
        }
        println(ans)
    }
}