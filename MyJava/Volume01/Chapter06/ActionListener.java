import java.awt.*;
import java.awt.event.ActionEvent;
import java.time.Instant;

public interface ActionListener {
    void actionPerformed(ActionEvent event);
}

class TimePrinter implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent event) {
        System.out.println("At the tone, the time is "
                + Instant.ofEpochMilli(event.getWhen()));
        Toolkit.getDefaultToolkit().beep();
    }
}

