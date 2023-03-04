import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class CountString {
    public static void main(String[] args) throws IOException {
        String fileName = "D:\\CODE\\MyJava\\MyPractise\\Other\\a1.txt";  // 改为指定路径
        File file = new File(fileName);
        FileReader fr = new FileReader(file);
        try (BufferedReader br = new BufferedReader(fr)) {
            String line;
            String string = "";
            while ((line = br.readLine()) != null)
                string += line;
            char[] chs;  // 转换成char数组
            chs = string.toCharArray();
            Hashtable<String, Integer> dict = new Hashtable<>();
            int count;
            // System.out.println("字符串：" + string + "中小写字母有：");
            for (char ch = 'a'; ch < 'z'; ch++) {
                count = 0; // 计数器
                for (char c : chs)
                    if (ch == c)
                        count++;

                if (count != 0)
                    dict.put(String.valueOf(ch), count);
            }
            List<Map.Entry<String, Integer>> list = new ArrayList<>(dict.entrySet()); //转换为list
            list.sort((o1, o2) -> o2.getValue().compareTo(o1.getValue()));
            Collections.reverse(list);     //实现list集合逆序排列
            //for-each循环
            int max = 1;
            for (Map.Entry<String, Integer> mapping : list) {
                // System.out.println(mapping.getKey() + ": " + mapping.getValue());
                if (mapping.getValue() == max) {
                    for (int i = 0; i < max; i++)
                        System.out.print("#");
                    max += 1;
                    System.out.println('\n');
                }

            }
        }
    }

}
