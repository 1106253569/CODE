import org.apache.spark.{SparkConf, SparkContext}

object WordCount {
  def main(args: Array[String]): Unit = {
    // 创建 SparkConf 对象，并设置应用程序的名称
    val conf = new SparkConf().setAppName("WordCount")

    // 创建 SparkContext 对象
    val sc = new SparkContext(conf)

    // 读取输入文件，将每行文本拆分为单词并计数
    val lines = sc.textFile("file:///workspaces/CODE/Spark/test.txt") // 输入文件路径
    val wordCounts = lines
      .flatMap(line => line.split(" "))
      .map(word => (word, 1))
      .reduceByKey(_ + _)

    // 打印每个单词及其计数
    wordCounts.collect().foreach { case (word, count) =>
      println(s"$word: $count")
    }

    // 停止 SparkContext 对象
    sc.stop()
  }
}
