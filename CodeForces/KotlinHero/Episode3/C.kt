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
        val N = rdInt()
        var ans = Array(N){0}
        val a = rdList()
        var minpos = 10000000
        var maxneg = -10000000
        var minpos_idx = -1
        var maxneg_idx = -1
        for (i in 0..N-1) {
            if (a[i] > 0) {
                ans[i] = 1
                if (a[i] < minpos) {
                    minpos = a[i]
                    minpos_idx = i
                }
            } else {
                ans[i] = 0
                if (a[i] < 0 && a[i] > maxneg) {
                    maxneg = a[i]
                    maxneg_idx = i
                }
            }
        }
        if (maxneg_idx == -1) {
            ans[minpos_idx] = 0
        } else if (minpos_idx == -1) {
            ans[maxneg_idx] = 1
        } else {
            if (-maxneg < minpos) {
                ans[maxneg_idx] = 1
            } else {
                ans[minpos_idx] = 0
            }
        }
        var sum = 0
        for (i in 0..N-1) {
            sum += ans[i] * a[i]
        }
        println(sum)
        println(ans.joinToString(""))
    }
}