import scala.io.StdIn
object hello {
  def main(args: Array[String]): Unit = {
    // 常量
    var a: Int = 10
    // 变量
    val b: Float = 5
    a = a / 2
    // 字符串，通过+号连接
    val word: String = "Hello" + " " + "world"
    // printf格式化输出：字符串，通过%传值
    println(word)
    // 字符串模板（插值字符串）:通过$获取变量值
    printf("a=%d\n", a)
    // 输入
    printf("please enter name: ")
    val name: String = StdIn.readLine()
    printf("please enter age: ")
    var age: Int = StdIn.readInt()
    println(s"Welcome ${age} years student ${name}!")
    if (age >= 18) {
      for (i <- age to { 18 } by -1) {
        println(s"${i} BinaryString is ${i.toBinaryString}")
      }
    }
    // 设置50-100之间的五个整数用于测试函数
    val score = Range(50, 100, step = 10)
    for (i <- score.reverse) {
      println(s"$i: ${scoreChange(i)}")
    }
  }

  private def scoreChange(score: Double): Char = {
    val result =
      if (score >= 90) 'A'
      else if (score >= 80) 'B'
      else if (score >= 70) 'C'
      else if (score >= 60) 'D'
      else 'E'
    return result
  }
}
