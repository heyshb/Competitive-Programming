import kotlin.system.exitProcess
import java.util.*
//exitProcess(0)

fun rd() = readLine()!!
fun rdInt() = rd().toInt()
fun rdList() = rd().split(' ').map{it.toInt()}.toMutableList()
var arr = Array(500000){0}
var N = 0
var M = 0
val startComparator = Comparator { m1: movie, m2: movie -> m1.start - m2.start }


class movie(var start:Int, var end:Int, var id:Int): Comparable<movie> {
    override fun compareTo(other: movie): Int {
        return this.end - other.end
    }
}

var a = Array(0){movie(0,0,0)}
var b = List(0){movie(0,0,0)}
var ans = Array(0){0}

fun check(d:Int) : Boolean {
    var node = 0
    val heap = PriorityQueue<movie>()
    var now = b[0].start
    while(node < N || heap.isNotEmpty()) {
        while(node < N && b[node].start <= now) {
            heap.add(b[node])
            node += 1
        }
        /*
        println("fuck $M")
        println(now)
        println(heap.size)
        */
        for (i in 1..M) {
            if (heap.isEmpty()) {
                break
            }
            val mm = heap.poll()
            if (mm.end + d < now) {
                return false
            }
            ans[mm.id] = now
        }
        if (heap.isEmpty()) {
            if (node < N) {
                now = b[node].start
            }
        } else {
            now += 1
        }
    }
    return true
}

fun main(args: Array<String>) {
    val T = rdInt()
    repeat(T) {
        var (uN, uM) = rdList()
        N = uN
        M = uM
        a = Array(N){movie(0,0,0)}
        for (i in 0..N-1) {
            var (u, v) = rdList()
            a[i].start = u
            a[i].end = v
            a[i].id = i
        }
        b = a.sortedWith(startComparator)
        ans = Array(N){0}
        
        /*
        for (m in b) {
            println("${m.start} ${m.end} ${m.id}")
        }
        */
        if (check(0)) {
            println(0)
            println(ans.joinToString(" "))
        } else {
            var L = 0
            var R = 200001
            while(L < R - 1) {
                var mid = (L + R) / 2
                if (check(mid)) {
                    R = mid
                } else {
                    L = mid
                }
            }
            println(R)
            check(R)
            println(ans.joinToString(" "))
        }
    }

}