fun add(a: Int, b: Int): Int {
    return a + b
}

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    for (i in 1..n step 5) {
        println("fuck$i")
    }
    println(add(1, 2))
    println("Hello!")    
}