fun main(args: Array<String>) {
    val v = readLine()!!.split(' ').map{it.toInt()}.sorted()
    for (i in 0..2) {
        println(v[3] - v[i])
    }
}