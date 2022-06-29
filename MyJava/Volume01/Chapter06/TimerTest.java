import javax.swing.*;
import java.awt.*;
import java.time.Instant;


public class TimerTest {
    public static void main(String[] args) {
        /*var listener = new TimePrinter();
         *var timer = new Timer(1000, (ActionListener) listener);
         * */
        var timer = new Timer(1000, event -> {
            System.out.println("At the tone, the time is "
                    + Instant.ofEpochMilli(event.getWhen()));
            Toolkit.getDefaultToolkit().beep();
        });
        timer.start();

        JOptionPane.showMessageDialog(null, "Quit program");
        System.exit(0);

    }
}