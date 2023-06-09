import scala.collection.mutable.*
object ObjectTest {
  def main(args: Array[String]): Unit = {
    val arr1: Array[Int] = new Array[Int](5)
    val arr2 = Array(12, 23, 34, 45, 56)
    for (i <- 0 until { arr2.length }) {
      arr1(i) = arr2(arr2.length - 1 - i)
      println(arr1(i))
    }
    for (elem <- arr2) println(elem)
    println(arr1.mkString("-"))
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

    val arr3: ArrayBuffer[Int] = arr1.to(ArrayBuffer)
    println(arr3.append(10).mkString("-"))
    println(arr3.prepend(10).mkString("-"))

    val map1: Map[String, Int] = Map(s1(0) -> 10, s1(1) -> 20, s1(2) -> 30)
    println(map1)
    map1.foreach(println)
    map1.foreach((kv: (String, Int)) => println(kv))
    val p1: Person = Person("Jack", map1("Jack"))
    p1.say()
  }
}

class Person(var name: String, val age: Int = 18) {
  def say(): Unit = {
    println(s"My name is ${name}, my age is ${age}")
  }
}
