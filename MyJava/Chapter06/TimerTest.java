import javax.swing.*;
import java.awt.event.ActionListener;


public class TimerTest {
    public static void main(String[] args) {
        var listener = new TimePrinter();

        var timer = new Timer(1000, (ActionListener) listener);
        timer.start();

        JOptionPane.showMessageDialog(null, "Quit program");
        System.exit(0);
    }
}
