object FunctionAndMethod {
  def main(args: Array[String]): Unit = {
    val res: Int = F1(1, 2)
    println(res)
    val list = List(1, 2, 3, 4, 5)
    val ints: List[Int] = list.map((x: Int) => { x + 1 })
    println(ints)
  }
  val F1 = (x1: Int, x2: Int) => { (x1 + x2) * x2 }
}
