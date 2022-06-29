import java.io.File;

public class fileTest {
    File[] hiddenFile1 = new File(".").listFiles(file -> file.isHidden());
    File[] hiddenFile2 = new File(".").listFiles(File::isHidden);
}
