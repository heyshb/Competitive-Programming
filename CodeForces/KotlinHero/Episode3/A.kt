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
        val v = rdInt()
        if (v < 1000) {
            println(v)
        } else if (v < 1000000) {
            var t = v / 1000
            if (v >= t * 1000 + 500) {
                t += 1
            }
            if (t == 1000) {
                println("1M")
            } else {
                println("${t}K")
            }
        } else {
            var t = v / 1000000
            if (v >= t * 1000000 + 500000) {
                t += 1
            }
            println("${t}M")
        }

    }
}