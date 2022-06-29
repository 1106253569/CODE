import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class MyAnimation {
    /*public String readData(Scanner in)
            throws EOFException {
        int i = 0;
        while (i < 10) {
            if (in.nextInt() < 10) {
                int n = in.nextInt();
                if (n < 100)
                    throw new EOFException();
            }
            i++;
        }
        return "1";
    }*/
    public String readData(Scanner in)
            throws FileNotFoundException {
        int i = 0;
        while (i < 10) {
            if (in.nextInt() < 10) {
                int n = in.nextInt();
                if (n < 100)
                    throw new FileNotFoundException();

            }
            i++;
        }
        assert i >= 101 : "i>=101";
        return "1";
    }
}

class FileFormatException extends IOException {
    public FileFormatException() {
    }

    public FileFormatException(String gripe) {
        super(gripe);
    }
}

