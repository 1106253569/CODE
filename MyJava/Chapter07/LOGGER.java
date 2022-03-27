import java.io.IOException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class LOGGER {
    private static final Logger myLogger = Logger.getLogger("com.myCompany.myapp");

    public static void main(String[] args) throws IOException {
        Logger.getGlobal().setLevel(Level.OFF);
        Logger.getGlobal().info("File->Open menu item selected");
        Scanner in = new Scanner(System.in);
        int i = in.nextInt();
        if (i < 0) {
            var e = new IOException("IO");
            myLogger.throwing("com.myCompany.myLib.Reader", "read", e);
            throw e;
        }
    }

    int read(String file, String pattern) {
        myLogger.entering("com.myCompany.myLib.Reader", "read",
                new Object[]{file, pattern});
        int count = 0;
        myLogger.exiting("com.myCompany.myLib.Reader", "read", count);
        return count;
    }


}
