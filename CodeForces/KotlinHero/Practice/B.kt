import kotlin.collections.*

fun main(args: Array<String>) {
    readLine()
    //val N = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map{it.toInt()}
    val ret = a.reversed().distinct().reversed()
    println(ret.size)
    println(ret.joinToString(" "))
}