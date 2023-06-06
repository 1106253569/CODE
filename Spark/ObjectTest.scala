object ObjectTest {
  def main(args: Array[String]): Unit = {
    val arr: Array[Int] = new Array[Int](5)
    val arr2 = Array(12, 23, 34, 45, 56)
    for (i <- 0 until { arr2.length }) {
      arr(i) = arr2(arr2.length - 1 - i)
      println(arr(i))
    }
    for (elem <- arr2) println(elem)
    println(arr.mkString("-"))
    val s1 = Array("Jack", "Jerry", "Mary")
    // :+ 在后添加元素
    println((s1 :+ "Tome").mkString(","))
    // .+:() 在前添加元素
    println((s1.+:("Tome")).mkString(","))
    val s2: Array[String] = new Array[String](2)
    s2(0) = "Tome"
    s2(1) = "Amy"
    println((s1 ++ s2).mkString(","))
    println((s1.++:(s2)).mkString(","))
  }
}
