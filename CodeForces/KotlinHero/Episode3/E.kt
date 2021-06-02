import kotlin.system.exitProcess
//exitProcess(0)

fun rd() = readLine()!!
fun rdInt() = rd().toInt()
fun rdList() = rd().split(' ').map{it.toInt()}.toMutableList()
var arr = Array(500000){0}
var ans1 = mutableListOf<Int>()
var e = Array(0, {ArrayList<Int>()})
var ans = mutableListOf<Int>()

fun dfs(x: Int, fa: Int, need:Int) : Int {
    var sum = 0
    var isLeaf = false
    for (t in e[x]) {
        if (t == fa) {
            continue;
        }
        isLeaf = true
    }
    return sum
}

fun main(args: Array<String>) {
    val T = rdInt()
    repeat(T) {
        val (N, K) = rdList()
        e = Array(N + 1, {ArrayList<Int>()})
        for (i in 1..N-1) {
            val (u, v) = rdList()
            e[u].add(v)
            e[v].add(u)
        }
        if (K == 1) {
            println("Yes")
            println(1)
        } else {
            var find = false
            for (t in e[1]) {
                ans = mutableListOf<Int>()
                if (dfs(t, 1, K - 1) == K - 1) {
                    ans.add(1)
                    println("Yes")
                    println(ans.size)
                    println(ans.joinToString(" "))
                    find = true
                    break
                }
            }
            if (!find) {
                ans = mutableListOf<Int>()
                if (dfs(1, 0, K) == K) {
                    println("Yes")
                    println(ans.size)
                    println(ans.joinToString(" "))
                } else {
                    println("No")
                }
            }
        }
    }
}