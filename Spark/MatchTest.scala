object MatchTest {
  def main(args: Array[String]): Unit = {
    val array = Array("Jack", "Tom")
    ArrayMatch(array)
    val list =
      List(List("Hadoop", "HBase", "Hadoop"), List("Spark", "Hive", "Spark"))
    val tuples = list.flatMap(x => (x.map((_, 1))))
    println(tuples)
    println(tuples.groupBy(x => (x)))
  }

  def ArrayMatch(array: Array[String]): Unit = {
    array match {
      case Array(x, y)       => println("数组长度为2: " + x + " " + y)
      case Array("Jack", _*) => println("Begin by Jack")
      case _                 => println("Other")
    }

  }
}
