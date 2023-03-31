import scala.io.StdIn

object IfForExerc {
  def main(args: Array[String]): Unit = {
    print("please enter age: ")
    val age:Int =StdIn.readInt()

    if(age>=18)
      println("成年")
      else
      println("未成年")
      
  }
}
