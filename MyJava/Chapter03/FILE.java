import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.util.Scanner;

public class FILE {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(Path.of("D:\\CODE\\Document\\sun.txt"), StandardCharsets.UTF_8);
        PrintWriter out = new PrintWriter("myFile.txt", StandardCharsets.UTF_8);
    }
}
