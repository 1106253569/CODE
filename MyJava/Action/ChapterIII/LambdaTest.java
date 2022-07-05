import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LambdaTest {
    String oneLine = processFile(BufferedReader::readLine);
    String twoLine = processFile((BufferedReader br) -> br.readLine() + br.readLine());

    public LambdaTest() throws IOException {
    }

    public static void main(String[] args) {
        /*
        (String s)->s.length();
        (Apple a)->a.getWeight()>150;
        ()->42
        (int x,int y)->{
            System.out.print("Result\n");
            System.out.print(x+y);
        }
         */

    }

    public static String processFile() throws IOException {
        try (BufferedReader br =
                     new BufferedReader(new FileReader("data.txt"))) {
            return br.readLine();
        }
    }

    public static String processFile(BufferedReaderProcessor p)
            throws IOException {
        try (BufferedReader br =
                     new BufferedReader(new FileReader("data.txt"))) {
            return p.process(br);
        }
    }

    public interface BufferedReaderProcessor {
        String process(BufferedReader b) throws IOException;
    }


}
