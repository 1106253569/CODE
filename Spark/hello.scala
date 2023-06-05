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
  }
}
